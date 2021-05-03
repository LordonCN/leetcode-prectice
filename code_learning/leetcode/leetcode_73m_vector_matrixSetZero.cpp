
#include <iostream>
#include <vector>
using namespace std;

/* -------------------------------------------
 * 思路：暴力 ac 12 9
 * ------------------------------------------*/
void setZeroes(vector<vector<int>>& matrix) {
    vector<vector<int>>number;
    // 找到所有的0
    for(int i = 0;i<matrix.size();i++)
    {
        for(int j = 0;j<matrix[0].size();j++)
        {
            if(matrix[i][j] == 0)number.push_back({i,j});
        }
    }
    for(auto res:number)
    {
        for(int i = 0;i<matrix.size();i++)
        {
            for(int j = 0;j<matrix[0].size();j++)
            {
                if(i == res[0])matrix[i][j] = 0;
                if(j == res[1])matrix[i][j] = 0;
            }
        }
    }
}

int main()
{
    vector<vector<int>>matrix{{1,1,1},{1,0,1},{1,1,1}};
    setZeroes(matrix);
    return 0;
}