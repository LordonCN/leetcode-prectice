#include <iostream>

using namespace std;

/* -------------------------------------------
 * 第n层台阶是由第n-1 与 n-2爬上来的
 * 1、递归实现[时间长 占用空间大]
 * 2、动态规划用数组保存结果[速度快 占用空间小]
 * ------------------------------------------*/
int climbstairs_DG(int n)
{
    int sum = 0;
    if(n == 0)return 1;
    if(n-1>=0) sum += climbstairs_DG(n-1);
    if(n-2>=0) sum += climbstairs_DG(n-2);
    return sum;
}

int climbstairs_DP(int n)
{
    int array[n+1];
    array[1] = 1;
    array[2] = 2;
    if(n<3) return n;
    else
    {
        for(int i = 3;i<=n;i++)
        {
            array[i] = array[i-1]+array[i-2];
        }
    }
    return array[n];
}

int main()
{
    int target = 21;

    climbstairs_DP(target);

    return 0;
}