#include <iostream>
#include <vector>

using namespace std;

/* -------------------------------------------
 * 上下左右四个位置进行限制性锁紧 ac 34 51
 * 如果没有内部停止判断对话最后一行不好判断 
 * break是成功的关键
 * ------------------------------------------*/
vector<int> spiralOrder(vector<vector<int>>& matrix) {
    int u = 0;
    int l = 0;
    int r = matrix[0].size()-1;
    int d = matrix.size()-1;
    vector<int>output;
    int i = l;
    while(true)
    {
        while(i <= r) output.push_back(matrix[u][i++]);
        if(++u>d)break; 
        i = u;
        while(i <= d) output.push_back(matrix[i++][r]);
        if(--r<l)break; 
        i = r;
        while(l <= i) output.push_back(matrix[d][i--]);
        if(--d<u)break; 
        i = d;
        while(i >= u) output.push_back(matrix[i--][l]);
        if(++l>r)break; 
        i = l;
    }
    return output;
}

int main()
{
    vector<vector<int>>matrix{{1,2,3,6},{4,5,6,6},{7,8,9,6}};
    spiralOrder(matrix);
    return 0;
}
