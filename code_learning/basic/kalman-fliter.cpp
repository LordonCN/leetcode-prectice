// gaussian noise generate
#include <iostream>
#include <math.h>
#include <random>// normal_distribution
#include <time.h>

/* -------------------------------------------
 * 生成高斯噪声
 * 网上找的 其实是固定数的噪声
 * Q 影响滤波后曲线形状 往小调平滑性增高
 * R 对观测值的信任程度
 * resrcdata[0] 不敏感 给的区别很大也没有关系
 * ------------------------------------------*/
float Kalman_Filter(const float ResrcData,float ProcessNiose_Q,float MeasureNoise_R)
{
    float R = MeasureNoise_R;
    float Q = ProcessNiose_Q;
    float k = 0.01;
    float h = 0.95;// 能够明显改变滤波倾向大小
    float F1 = 1.0;

    static float x_last = 0.01;// 存储之前的值
    static float p_last = 0.01;

    float x_min;
    float x_now;

    float p_min;
    float p_now;

    x_min = x_last * F1; //
    p_min = p_last * F1 * F1 + Q; //Q=噪声

    k = h * p_min / (h * h * p_min+R); //kg为kalman filter，R为噪声

    x_now = x_min + k * (ResrcData - h * x_min);//估计出的最优值
    p_now = (1 - k * h) * p_min;//最优值对应的covariance

    p_last = p_now; //更新covariance值
    x_last = x_now; //更新系统状态值

    return x_now;
}

void kalman_test()
{
    int n = 100;
    vector<double>state(n,0);

    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine generator(seed);
    std::normal_distribution<double> distribution(0.0, 0.2);// 期望0 方差0.2

    for(int i = 0;i<n;i++)
        state[i] = i + distribution(generator);

    for(int i = 0;i<n;i++)
        state[i] = Kalman_Filter(state[i], 0.2, 0.1);// QR需要不断自己调 经验值
    int a = 0;
}

int main()
{
    kalman_test();

    return 0;
}
