// gaussian noise generate
#include <math.h>
#include <numeric>
#include <iostream>

/* -------------------------------------------
 * 生成高斯噪声
 * 网上找的 其实是固定数的噪声
 * ------------------------------------------*/
double generateGaussianNoise(double mu, double sigma)
{
    const double epsilon = std::numeric_limits<double>::min();
    const double two_pi = 2.0*3.14159265358979323846;

    static double z0, z1;
    static bool generate;
    generate = !generate;

    if (!generate)
        return z1 * sigma + mu;

    double u1, u2;
    do
    {
        u1 = rand() * (1.0 / RAND_MAX);
        u2 = rand() * (1.0 / RAND_MAX);
    } while (u1 <= epsilon);

    z0 = sqrt(-2.0 * log(u1)) * cos(two_pi * u2);
    z1 = sqrt(-2.0 * log(u1)) * sin(two_pi * u2);
    return z0 * sigma + mu;
}

/* -------------------------------------------
 * kalman filter
 * ------------------------------------------*/
float Kalman_Filter(const float ResrcData,float ProcessNiose_Q,float MeasureNoise_R)
{
    float R = MeasureNoise_R;
    float Q = ProcessNiose_Q;

    static float x_last = 0.01;// 存储之前的值
    static float p_last = 0.01;

    float x_mid;
    float x_now;

    float p_mid;
    float p_now;

    float k = 0.01;
    float h = 0.95;// 能够明显改变滤波倾向大小

    x_mid = x_last; //
    p_mid = p_last + Q; //Q=噪声

    k = h * p_mid / (h * h * p_mid+R); //kg为kalman filter，R为噪声

    x_now = x_mid + k * (ResrcData - h * x_mid);//估计出的最优值
    p_now = (1 - k * h) * p_mid;//最优值对应的covariance

    p_last = p_now; //更新covariance值
    x_last = x_now; //更新系统状态值

    return x_now;
}

int main()
{
    vector<double>state(10,0);

    for(int i = 0;i<10;i++)
        state[i] = 3 * i + generateGaussianNoise(0, 0.5);// mu sigma

        // 有效果
    for(int i = 0;i<10;i++)
        state[i] = Kalman_Filter(state[i], 0.22, 0.1);

    return 0;
}
