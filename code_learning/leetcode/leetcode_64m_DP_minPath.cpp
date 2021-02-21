#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

/* -------------------------------------------
 * 注意：ac 84% 71%
 * 二维状态转移 难度不大
 * 只能向下或者向右移动
 * ------------------------------------------*/
int DPshuLie(vector<vector<int>>&nums)
{
    int m = nums.size(),n = nums[0].size();
    vector<vector<int>>dp(m,vector<int>(n,0));//初始化固定大小vector
    for(int i = 0;i<m;i++) // 下移
    {
        for(int j = 0;j<n;j++) // 右移
        {
            if(i == 0&&j == 0)// 填充第一个
                dp[i][j] = nums[i][j];
            else if(i == 0) //填充第一行
                dp[i][j] = dp[i][j-1] + nums[i][j];
            else if(j == 0) //填充第一列
                dp[i][j] = dp[i-1][j] + nums[i][j];
            else //其余部分取最小值补全
                dp[i][j] = min(dp[i][j-1],dp[i-1][j])+nums[i][j];
        }
    }

    return dp[m-1][n-1];
}

int main()
{
    vector<vector<int>> nums{{1,2,3},{4,5,6}};

    DPshuLie(nums);
    return 0;
}