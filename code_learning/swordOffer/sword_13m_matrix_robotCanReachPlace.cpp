#include <iostream>
//#include "listNode.h"
#include <vector>
#include <algorithm>

using namespace std;

/* -------------------------------------------
 * 无ac
 * 参考12题的深度遍历
 * 关键：方向数组的用法
    vector<int>dx{0,1,0,-1};
    vector<int>dy{1,0,-1,0};
 * ------------------------------------------*/
int sum = 0;
int movingCount(int m, int n, int k) {
    // 存储遍历状态 可达为1
    vector<vector<int>>state(m,vector<int>(n,0));
    DFS(0,0,m,n,state,k);
    // 结果直接求和
    for(int i = 0;i<m;i++)
    {
        for(int j = 0;j<n;j++)
        {
            sum += state[i][j];
        }
    }
    return sum;
}
void DFS(int i,int j,int m,int n,vector<vector<int>>&state,int k)
{
    // 终止条件
    if((i+j)>k)return;
    else state[i][j] = 1;
    // 方向数组
    vector<int>dx{0,1,0,-1};
    vector<int>dy{1,0,-1,0};
    // 当前点的四个方向
    for(int d = 0;d<4;d++)
    {
        int x = i + dx[d],y = j + dy[d];
        if(x < 0 || y < 0 || x >=m || y >= n || state[x][y] )// 先不加减枝
            continue;
        DFS(x,y,m,n,state,k);
    }
}