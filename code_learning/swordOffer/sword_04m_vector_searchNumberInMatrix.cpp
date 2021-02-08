#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/* -------------------------------------------
 * 思路：
 * 1、首先竖着判断位于第几行 再横着搜看是否存在对应值
 * 2、从右上角开始判断大小 向下向左移动即可
 * ------------------------------------------*/
bool searchMatrix(const vector<vector<int>>&matrix,int number)
{
    if(number<matrix[0][0]) return false;
    if(number>matrix[matrix.size()][matrix[0].size()]) return false;
    // 行
    for(int i = 0 ;i < matrix.size();i++)
    {
        // 是否比当前行最小的大 比最大的小
        if(matrix[i][0] < number && matrix[i][matrix[i].size()] > number)
        {
            for(int j = 0;j <matrix[i].size();j++)
            {
                if(matrix[i][j] == number) return true;
            }
        }
    }
    return false;
}

bool findNumberIn2DArray(const vector<vector<int>>&matrix,int number)
{

    if(number<matrix[0][0]) return false;
    if(number>matrix[matrix.size()][matrix[0].size()]) return false;
    // 行
    int row = 0;
    int yaw =matrix[0].size();

    while(row<matrix.size() && yaw>=0)
    {
        if(matrix[row][yaw] < number ) row++;
        else if (matrix[row][yaw] > number ) yaw--;
        else return true;
    }
    return false;
}


int main()
{
    // n*n
//    vector<vector<int>> nums{{21,3},{2,5}};
    vector<vector<int>> nums{{1,2,3},{4,5,6},{7,8,9}};
    int seartchNumber = 5;

    findNumberIn2DArray(nums,seartchNumber);

    return 0;
}