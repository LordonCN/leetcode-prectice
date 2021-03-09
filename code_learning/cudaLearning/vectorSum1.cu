#include "cuda_runtime.h"
#include "device_launch_parameters.h"
#include <stdio.h>
#include <iostream>
#include <cuda.h>
#include <ctime>

// 初步实现功能 并进行测试

using namespace std;
// 对向量的运算
__global__ void addkernel(int *c,const int *a,const int *b)
{
    int i = threadIdx.x;

// 默认情况下i是从0开始进行调用哎哎的,所以可以用这种方法进行计算
// 只有编译能力2.0以上的显卡才可以调用printf
// 这里不建议使用printf 调试的话应该在cpu上进行输出显示
// printf("now i is %d in thread.\n",i); //该输出可以查看调用的线程序号

    c[i] = a[i] + b[i];

}

int main()
{
    const int arraySize = 20;

    const int a[arraySize] = {1,2,3,4,5,1,2,3,4,5,1,2,3,4,5,1,2,3,4,5};
    const int b[arraySize] = {10,20,30,40,50,10,20,30,40,50,10,20,30,40,50,10,20,30,40,50};
    int c[arraySize] = {0};

// 调用进程块与线程总数为 gd*dt
    int gd = 1;
    int dt = arraySize;

// 测试线程数对计算速度的影响
    clock_t startTime,endTime;
    startTime = clock();
    int *dev_a,*dev_b,*dev_c;

// cuda状态监测
    cudaError_t cudaStatus;

    cudaStatus = cudaSetDevice(0);
    if(cudaStatus == cudaSuccess)
        cout<<"setDevice successful"<<endl;
    else
    {
        cout<<"setDevice failed!"<<endl;
        goto ERROR;
    }


// 创建cuda内存
    cudaStatus = cudaMalloc((void**)&dev_c, arraySize * sizeof(int));
    cudaStatus = cudaMalloc((void**)&dev_a, arraySize * sizeof(int));
    cudaStatus = cudaMalloc((void**)&dev_b, arraySize * sizeof(int));
    if (cudaStatus == cudaSuccess){
        cout<<"cudaMalloc successful"<<endl;
    }
    else
    {
        cout<<"setDevice failed!"<<endl;
        goto ERROR;
    }


// 将ab传到显卡上
    cudaStatus = cudaMemcpy(dev_a,a,arraySize * sizeof(int),cudaMemcpyHostToDevice);
    cudaStatus = cudaMemcpy(dev_b,b,arraySize * sizeof(int),cudaMemcpyHostToDevice);
    if (cudaStatus == cudaSuccess){
        cout<<"cudacpy successful"<<endl;
    }
    else
    {
        cout<<"cudacpy failed"<<endl;
        goto ERROR;
    }


// 调用kernel函数 网格中线程块为1 线程块中包括5个线程
// 所有线程调用结束后返回
    addkernel<<<gd,dt>>>(dev_c,dev_a,dev_b);


// 这个地方是由设备c传回cpu-c deviceToHost 第一次在这里卡了好久
    cudaStatus = cudaMemcpy(c,dev_c,arraySize * sizeof(int),cudaMemcpyDeviceToHost);
    if (cudaStatus == cudaSuccess){
        cout<<"cudacpy successful"<<endl;
    }
    else
    {
        cout<<"cudacpy failed"<<endl;
        goto ERROR;
    }

    endTime = clock();


    ERROR:
    cudaFree(dev_c);
    cudaFree(dev_a);
    cudaFree(dev_b);

    cout<<"run time is:"<<endTime-startTime<<" And result is:"
        <<c[0]<<" "<<c[1]<<" "<<c[2]<<" "<<c[3]<<" "<<c[4]
        <<c[5]<<" "<<c[6]<<" "<<c[7]<<" "<<c[8]<<" "<<c[9]
        <<c[10]<<" "<<c[11]<<" "<<c[12]<<" "<<c[13]<<" "<<c[14]
        <<endl;


    return 0;
}