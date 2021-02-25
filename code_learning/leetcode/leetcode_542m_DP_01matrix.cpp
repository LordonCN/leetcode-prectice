#include <iostream>
#include <vector>

using namespace std;

/* -------------------------------------------
 * 注意
 * 执行用时：97.82% 内存消耗：85.25%
 * 打脸：与普通二维dp相比这个没有规定只有固定方向循迹 遵循从上到下 从左到右的方法行不通
 * 1-BFS搜索 图相关类型题目
 * 2-DP 二维 从左上到右下的搜索 [17 19]行的判断方法减少了判断条件
 * ------------------------------------------*/
vector<vector<int>> DPmatrix(vector<vector<int>>&nums)
{
    int m = nums.size(),n = nums[0].size();
    vector<vector<int>>dp(m,vector<int>(n,10001)) ;//初始化固定大小vector

    // 左上方
    for(int i = 0;i<m;i++) // 下移
    {
        for(int j = 0;j<n;j++) // 右移
        {
            if(nums[i][j]==0)
            {
                dp[i][j] =0;// change 10001 to 0
                continue;
            }
            if(j>0)
                dp[i][j]= min(dp[i][j-1]+1,dp[i][j]); // 与左侧的距离 与0
            if(i>0)
                dp[i][j]= min(dp[i-1][j]+1,dp[i][j]); // 与左侧的距离 上侧的距离
        }
    }

    for(int i = m-1;i>=0;i--) // 下移
    {
        for(int j = n-1;j>=0;j--) // 右移
        {
            if(j<n-1)
                dp[i][j]= min(dp[i][j+1]+1,dp[i][j]);
            if(i<m-1)
                dp[i][j]= min(dp[i][j],dp[i+1][j]+1);
        }
    }
    return dp;
}

int main()
{
    vector<vector<int>> nums{{0,0,1},{0,0,1},{1,1,1}};

    DPmatrix(nums);
    return 0;
}