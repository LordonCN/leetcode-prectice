#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/* -------------------------------------------
 * 思路：ac 100 26
 * 首先对矩阵按照对角线进行对称翻转 swap
 * 再对内部vector reverse  注意auto后面取地址
 * ------------------------------------------*/
void matrixRotate(vector<vector<int>>&matrix)
{
    for(int i = 0 ;i < matrix.size();i++)
    {
        // attention i = j
        for(int j = i;j <matrix.size();j++)
        {
            swap(matrix[i][j],matrix[j][i]);
        }
    }
}

int main()
{
    // n*n
//    vector<vector<int>> nums{{21,3},{2,5}};
    vector<vector<int>> nums{{1,2,3},{4,5,6},{7,8,9}};

    matrixRotate(nums);
    // 向右旋转90度
    for(auto &i : nums)
        reverse(i.begin(),i.end());

    return 0;
}