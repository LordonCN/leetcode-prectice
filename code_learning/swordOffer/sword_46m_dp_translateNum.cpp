#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*************************************************************************
 * offer
 *======================================================================*/
int movingCount(int m,int n,int k)
{
    int result;
    vector<vector<int>>dp(m,vector<int>(n,0));
    dp[0][0] = 1;

    int row = 0,yaw = 0;
    // 数位之和判断
    int judge_1_g = row%10;
    int judge_1_s = row/10;
    int judge_2_g = yaw%10;
    int judge_2_s = yaw/10;








    return result;
}

int main()
{
    int m =12,n=23,k=18;

    movingCount(m,n,k);

    return 0;
}