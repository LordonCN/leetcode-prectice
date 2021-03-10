#include <iostream>
#include <vector>

using namespace std;
/*************************************************************************
 * 一维数组计算思路
 * dp思路 ac 39 14
 *======================================================================*/
int maxProfit(vector<int>& nums)
{
    vector<int>result(nums.size(),0);
    int minInput = nums[0];

    for(int i = 1;i<nums.size();i++)
    {
        if(nums[i]<minInput)minInput =nums[i];
        if(nums[i]-minInput>result[i-1])
            result[i] = nums[i] - minInput;
        else
            result[i] = result[i-1];
    }
    return result[nums.size()-1];
}
/*************************************************************************
 * 二维数组计算速度满了 存储上升了
 *======================================================================*/
void methord121_2(vector<int>& nums)
{
    vector<vector<int>> result(nums.size(),vector<int>(3,0));
    result[0][0] = 0;
    result[0][1] = -nums[0];

    vector<vector<vector<int>>> dp(nums.size(),vector<vector<int>>(3,vector<int>(2,0)));
    for(int i = 1;i<nums.size();i++)
    {
        result[i][0] = max(result[i-1][0],result[i-1][1]+nums[i]);
        result[i][1] = max(result[i-1][1],-1 * nums[i]);
    }
    return ;
}
/*************************************************************************
 * 三维通解测试
 * result[i][k][0]  k=1 的时候代表着只进行一次交易 创建n*(k+1)*2的三维数组 对于k-1的情况一直为零 所以能够变形
 *======================================================================*/
void methord121_3(vector<int>& nums)
{
    int k = 1;
    vector<vector<vector<int>>> dp(nums.size(),vector<vector<int>>(k+1,vector<int>(2,0)));
    // k此时不起作用 为可以交易无数次的情况
    dp[0][k][0] = 0;
    dp[0][k][1] = -nums[1];

    for(int i = 1;i<nums.size();i++)
    {
        dp[i][k][0] = max(dp[i-1][k][0],dp[i-1][k][1]+nums[i]);
        dp[i][k][1] = max(dp[i-1][k][1],dp[i-1][k-1][0]-nums[i]);// -1 * nums[i]
    }
    return ;
}

int main()
{
    vector<int>nums{7,1,2,5,4,7,5}; // max = 6
    methord121_3(nums);
    return 0;
}