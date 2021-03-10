#include <iostream>
#include <vector>

using namespace std;
/*************************************************************************
 * 三维通解测试 可以任意交易次数的时候
 * result[i][k][0]  k
 * 这里任取k=0 所以创建维度为n*(k+1)*2 的三维数组 k趋近于无穷的时候k-1≈k 所以用k取代k-1即可
 *======================================================================*/
void methord188_Common(int k,vector<int>& nums)
{
    vector<vector<vector<int>>> dp(nums.size(),vector<vector<int>>(k+1,vector<int>(2,0)));
    // k此时不起作用 为可以交易无数次的情况
    if(!nums.size() || k ==0) return 0;
    // 初始化k维度的初始状态
    int k_temp  = k;
    while(k_temp--)
    {
        dp[0][k_temp+1][0] = 0;
        dp[0][k_temp+1][1] = -nums[0];
    }

    for(int i = 1;i<nums.size();i++)
    {
        int epoch = k;
        // 对k维度的状态进行迭代
        while(epoch--)
        {
            dp[i][epoch+1][0] = max(dp[i-1][epoch+1][0],dp[i-1][epoch+1][1]+nums[i]);
            dp[i][epoch+1][1] = max(dp[i-1][epoch+1][1],dp[i-1][epoch][0]-nums[i]);
        }
    }
    //return dp[nums.size()-1][k][0];
    return ;
}
int main()
{
    vector<int>nums{7,1,2,5,4,7,5}; // max = 7
    int k = 2;
    methord123_Common(k,nums);
    return 0;
}