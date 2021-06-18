#include <iostream>
#include <vector>

using namespace std;

#include <limits>
#include <numeric>
/*
 * 理解为使用n个来塞满书包即可 完全背包
 * 第一次遍历的时候只能用最少的来塞满 甚至塞不满-->416问题 塞不满时候 01背包
 * ac 47 20
 */
void coinChange322(vector<int>nums,int sum,vector<int>&dp)
{
    dp[0] = 0;
    for(int i = 0;i<nums.size();i++)
        for(int j = nums[i];j<=sum;j++)
        {
            dp[j] = min(dp[j],dp[j-nums[i]]+1);
        }
    return;
}

int main()
{
    // leetcode322
    vector<int>nums{2};
    int sum = 3;
    vector<int>dp(sum+1,INT_MAX-50);
    coinChange322(nums,sum,dp);

    return 0;
}
