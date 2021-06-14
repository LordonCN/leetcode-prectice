#include <iostream>
#include <unordered_map>
#include <vector>
#include <numeric>

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
/*
 * ac 82 97 布尔实现 自己做
 * */
bool canPartition(vector<int>& nums) {
    int sum = accumulate(nums.begin(),nums.end(),0);
    if(sum%2 != 0)return false;
    int target = sum/2;
    vector<bool>dp(sum,false);// 这里可以创建的大一点 否则会出现索引失败的问题
    for(int i = 0;i<nums.size();i++)
    {
        for(int j = target;j>=nums[i];j--)
        {
            dp[j] = (bool)(dp[j] || dp[j-nums[i]]);
        }
        dp[nums[i]] = true;// 遍历之后再将该number置位
        if(dp[target])break;
    }
    return dp[sum/2];
}
int main()
{
    // leetcode416
    vector<int>nums{1,2,5};
    int sum = accumulate(nums.begin(),nums.end(),0);
    // 存放可以取到的值
    vector<int>dp(sum/2+1,0);

//    canPartain416(nums,sum/2,dp);
    canPartition(nums);

    return 0;

}
