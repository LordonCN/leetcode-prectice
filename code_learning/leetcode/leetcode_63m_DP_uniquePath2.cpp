#include <vector>
#include <iostream>

using namespace std;

/* -------------------------------------------
 * 注意：ac 85.31% 80.83%
 * 第n个位置可由左边或者上面走过来的
 * 相比62T多了一个障碍是否存在的判断
 * ------------------------------------------*/
int uniquePathsWithObstacles(vector<vector<int>>& grid)
{
    int m = grid.size(),n = grid[0].size();
    vector<vector<int>>dp(m,vector<int>(n,0));
    if(grid[m-1][n-1] == 1 )return 0; //特殊情况 终点为石头
    if(grid[0][0] == 1) return 0; // 特殊情况 起点为石头
    else dp[0][0] = 1;

    for(int i = 0;i<m;i++)
    {
        for(int j = 0;j<n;j++)
        {
            if(i == 0 && j == 0) continue;
            if((i-1)>=0 && j-1>=0)
            {
                if(!grid[i][j-1])
                    dp[i][j] +=  dp[i][j-1];
                if(!grid[i-1][j])
                    dp[i][j] += dp[i-1][j];
            }
            else if((i-1)<0 && (j-1)>=0)//第一行
            {
                if(!grid[i][j-1])
                    dp[i][j] += dp[i][j-1];
            }
            else
            {
                if(!grid[i-1][j]) //第一列
                    dp[i][j] += dp[i-1][j];
            }
        }
    }
    return dp[m-1][n-1];
}

int main()
{
    vector<vector<int>>grid{{0,0,0},{0,1,0},{0,0,0}};
    uniquePathsWithObstacles(grid);
    return 0;
}