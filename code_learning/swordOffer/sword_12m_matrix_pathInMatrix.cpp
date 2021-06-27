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
bool finished;
bool exist(vector<vector<char>>& board, string word) {
    // 当前值是否使用过的
    vector<vector<bool>>used(board.size(),vector<bool>(board[0].size(),false));
    // 遍历第一个的x,y位置
    for(int i = 0;i<board.size();i++)
    {
        for(int j = 0;j<board[0].size();j++)
        {
            if(board[i][j] == word[0])
            {
                used[i][j] = true;
                DFS(1,i,j,board,word,used);
                used[i][j] = false;
            }
            if(finished)
                return finished;
        }
    }
    return finished;
}
bool DFS(int sum,int i,int j,vector<vector<char>>&board,string word,vector<vector<bool>>used){
    if(sum == word.length())
    {
        finished = true;
        return finished;
    }
    vector<int>dx{0,1,0,-1};
    vector<int>dy{1,0,-1,0};
    for(int d = 0;d<4;d++)
    {
        int x = i + dx[d],y = j + dy[d];
        // 坐标越界 或者 当前格子已经被使用了  就直接结束此次循环
        if(x < 0 || y < 0 || x >= board.size() || y >= board[0].size() || used[x][y]){
            continue;
        }

        if(board[x][y] == word[sum]){
            // 标记被使用
            used[x][y] = true;
            DFS(sum + 1, x, y,board,word,used);
            // 恢复现场
            used[x][y] = false;
        }
    }
    return false;
}