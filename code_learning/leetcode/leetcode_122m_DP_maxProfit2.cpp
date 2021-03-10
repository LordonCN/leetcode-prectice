#include <iostream>
#include <vector>

using namespace std;
/*************************************************************************
 * dp思路 ac 7.68 5.07
 *======================================================================*/
int methord122(vector<int>& nums)
{
    vector<vector<int>>result(nums.size(),vector<int>(2,0));
    result[0][0] = 0;
    result[0][1] = -nums[0];

    for(int i = 1;i<nums.size();i++)
    {
        result[i][0] = max(result[i-1][0],result[i-1][1]+nums[i]);
        result[i][1] = max(result[i-1][1],result[i-1][0]-nums[i]);
    }
    return result[nums.size()-1][0];
}
/*************************************************************************
 * 三维通解测试 可以任意交易次数的时候
 * result[i][k][0]  k趋近于无穷大 可以忽略
 * 这里任取k=0 所以创建维度为n*(k+1)*2 的三维数组 k趋近于无穷的时候k-1≈k 所以用k取代k-1即可
 *======================================================================*/
void methord122_Common(vector<int>& nums)
{
    int k = 0;
    vector<vector<vector<int>>> dp(nums.size(),vector<vector<int>>(k+1,vector<int>(2,0)));
    // k此时不起作用 为可以交易无数次的情况
    dp[0][k][0] = 0;
    dp[0][k][1] = -nums[0];

    for(int i = 1;i<nums.size();i++)
    {
        dp[i][k][0] = max(dp[i-1][k][0],dp[i-1][k][1]+nums[i]);
        dp[i][k][1] = max(dp[i-1][k][1],dp[i-1][k][0]-nums[i]);// k-1≈k
    }
    return ;
}
int main()
{
    vector<int>nums{7,1,2,5,4,7,5}; // max = 7
    methord122_Common(nums);
    return 0;
}