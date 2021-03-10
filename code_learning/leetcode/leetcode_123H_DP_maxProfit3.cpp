#include <iostream>
#include <vector>

using namespace std;
/*************************************************************************
 * 三维通解测试 可以任意交易次数的时候
 * result[i][k][0]  k=2
 * 这里任取k=0 所以创建维度为n*(k+1)*2 的三维数组 k趋近于无穷的时候k-1≈k 所以用k取代k-1即可
 *======================================================================*/
void methord123_Common(vector<int>& nums)
{
    int k = 2;
    vector<vector<vector<int>>> dp(nums.size(),vector<vector<int>>(k+1,vector<int>(2,0)));
    // k此时不起作用 为可以交易无数次的情况
    dp[0][1][0] = 0;
    dp[0][1][1] = -nums[0];
    dp[0][2][0] = 0;
    dp[0][2][1] = -nums[0];

    for(int i = 1;i<nums.size();i++)
    {
        int epoch = 2;
        while(epoch--)
        {
            k = epoch+1;
            dp[i][k][0] = max(dp[i-1][k][0],dp[i-1][k][1]+nums[i]);
            dp[i][k][1] = max(dp[i-1][k][1],dp[i-1][k-1][0]-nums[i]);// k-1≈k
        }
    }
    // return dp[nums.size()-1][2][0];
    return ;
}
int main()
{
    vector<int>nums{7,1,2,5,4,7,5}; // max = 7
    methord123_Common(nums);
    return 0;
}