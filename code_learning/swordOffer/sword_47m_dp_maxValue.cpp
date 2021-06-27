#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxValue(vector<vector<int>>& grid) {
    // 从左上角到右下角的最长路径 djistra不好使了 而且不是有向图
    if(grid.empty())return 0;
    vector<vector<int>> dp(grid.size(),vector<int>(grid[0].size(),0));
    dp[0][0] = grid[0][0];
    for(int i = 1;i<grid[0].size();i++)//第一行填充
    {
        dp[0][i] = dp[0][i-1] + grid[0][i];
        cout<<dp[0][i];
    }

    for(int i = 1;i<grid.size();i++)//第一列填充
        dp[i][0] = dp[i-1][0] + grid[i][0];

    for(int i = 1;i<grid.size();i++)
    {
        for(int j = 1;j<grid[0].size();j++)
            dp[i][j] = max(grid[i][j] + dp[i-1][j],grid[i][j] + dp[i][j-1]);
    }
    return dp[grid.size()-1][grid[0].size()-1];
}

int main()
{
    vector<vector<int>>nums{{1,2,3},{2,3,4},{4,5,6}};

    maxValue(nums);

    return 0;
}