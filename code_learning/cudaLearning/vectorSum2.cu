#include "cuda_runtime.h"
#include "device_launch_parameters.h"
#include <stdio.h>
#include <iostream>
#include <cuda.h>
#include <time.h>
#include <sys/time.h>

// 参考stackoverflow大佬 添加kernel_wapper function and timecal

using namespace std;
// 对向量的运算
__global__ void addkernel(int *c,const int *a,const int *b)
{
    register int i = threadIdx.x;

// 默认情况下i是从0开始进行调用哎哎的,所以可以用这种方法进行计算
// 只有编译能力2.0以上的显卡才可以调用printf
// 这里不建议使用printf 调试的话应该在cpu上进行输出显示
// printf("now i is %d in thread.\n",i); //该输出可以查看调用的线程序号

    c[i] = a[i] + b[i];

}


void kernel_wapper(int*dev_a,int *dev_b,int *dev_c,const int a[],const int b[],int c[],int arraySize)
{
    cudaError_t cudaStatus;
// 创建cuda内存
    cudaStatus = cudaMalloc((void**)&dev_c, arraySize * sizeof(int));
    cudaStatus = cudaMalloc((void**)&dev_a, arraySize * sizeof(int));
    cudaStatus = cudaMalloc((void**)&dev_b, arraySize * sizeof(int));
    if (cudaStatus == cudaSuccess){
        cout<<"cudaMalloc successful"<<endl;
    }
    else{
        cout<<"setDevice failed!"<<endl;
    }

// 将ab传到显卡上
    cudaStatus = cudaMemcpy(dev_a,a,arraySize * sizeof(int),cudaMemcpyHostToDevice);
    cudaStatus = cudaMemcpy(dev_b,b,arraySize * sizeof(int),cudaMemcpyHostToDevice);
    if (cudaStatus == cudaSuccess){
        cout<<"cudacpy successful"<<endl;
    }
    else
        cout<<"cudacpy failed"<<endl;

// 调用kernel函数 网格中线程块为1 线程块中包括5个线程
// 所有线程调用结束后返回
    addkernel<<<1,arraySize>>>(dev_c,dev_a,dev_b);

// 这个地方是由设备c传回cpu-c deviceToHost 第一次在这里卡了好久
    cudaStatus = cudaMemcpy(c,dev_c,arraySize * sizeof(int),cudaMemcpyDeviceToHost);
    if (cudaStatus == cudaSuccess){
        cout<<"cudacpy successful"<<endl;
    }
    else
        cout<<"cudacpy failed"<<endl;

    cudaFree(dev_c);
    cudaFree(dev_a);
    cudaFree(dev_b);

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

    int *dev_a,*dev_b,*dev_c;

// 运行时间统计
    timeval t1,t2;
    unsigned long et;

// cuda状态监测
    cudaError_t cudaStatus;

// 显卡状态监测
    cudaStatus = cudaSetDevice(0);
    if(cudaStatus == cudaSuccess)
        cout<<"setDevice successful"<<endl;
    else
        cout<<"setDevice failed!"<<endl;

// 计时
    gettimeofday(&t1,NULL);

// kernel任务
    if(cudaStatus == cudaSuccess)
        kernel_wapper(dev_a,dev_b,dev_c,a,b,c,dt);

    gettimeofday(&t2,NULL);

// 输出时间
    et = ((t2.tv_sec * 1000000)+t2.tv_usec) - ((t1.tv_sec * 1000000) + t1.tv_usec);
    printf("time 1 = %ld us\n", et);



    cout<<"Result is:"
        <<c[0]<<" "<<c[1]<<" "<<c[2]<<" "<<c[3]<<" "<<c[4]
        <<c[5]<<" "<<c[6]<<" "<<c[7]<<" "<<c[8]<<" "<<c[9]
        <<c[10]<<" "<<c[11]<<" "<<c[12]<<" "<<c[13]<<" "<<c[14]
        <<endl;


    return 0;
}
