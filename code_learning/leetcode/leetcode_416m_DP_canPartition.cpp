#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

/*
 * 转化为找元素和为sum的一半
 * ac 20 63
 */
#include <math.h>
void canPartain416(vector<int>nums,int sum,vector<int>&dp)
{
    for(int i = 0;i<nums.size();i++)// 取第一个数字
    {
        for(int j = sum;j>=nums[i];j--)
        {
            dp[j] = max(dp[j],dp[j-nums[i]]+nums[i]);
        }
    }
    return;
}

int main()
{


    // leetcode416
    vector<int>nums{1,2,5};
    int sum = accumulate(nums.begin(),nums.end(),0);
    // 存放可以取到的值
    vector<int>dp(sum/2+1,0);

    canPartain416(nums,sum/2,dp);

    return 0;

}
