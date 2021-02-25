#include <vector>
#include <iostream>

using namespace std;

/* -------------------------------------------
 * 注意：ac 100% 53.75%
 * 第n个位置可由左边或者上面走过来的
 * ------------------------------------------*/

int uniquePath(int m,int n)
{
    vector<vector<int>>grid(m,vector<int>(n,0));

    for(int i = 0;i<m;i++)
    {
        for(int j = 0;j<n;j++)
        {
            if(i ==0&&j==0)
                grid[i][j] =  1;
            else if(i==0 && j>0)
                grid[i][j] = grid[i][j-1];
            else if(i>0 && j==0)
                grid[i][j] = grid[i-1][j];
            else
                grid[i][j] = grid[i][j-1] + grid[i-1][j];
        }
    }
    return grid[m-1][n-1];
}

int main()
{
    int m = 7,n = 3;

    uniquePath(m,n);

    return 0;
}