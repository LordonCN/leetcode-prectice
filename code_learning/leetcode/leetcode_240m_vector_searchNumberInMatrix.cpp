#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/* -------------------------------------------
 * 思路：
 * 首先竖着判断位于第几行
 * 再横着搜看是否存在对应值
 * ------------------------------------------*/
void searchMatrix(const vector<vector<int>>&matrix,int number)
{
    if(number<matrix[0][0]) return;
    if(number>matrix[matrix.size()][matrix[0].size()]) return;
    // 行
    for(int i = 0 ;i < matrix.size();i++)
    {
        // 是否比当前行最小的大 比最大的小
        if(matrix[i][0] < number && matrix[i][matrix[i].size()] > number)
        {
            for(int j = 0;j <matrix[i].size();j++)
            {
                if(matrix[i][j] == number) return ;
            }
        }
    }
    return;
}

void searchMatrix2(const vector<vector<int>>&matrix,int number)
{

    if(number<matrix[0][0]) return;
    if(number>matrix[matrix.size()][matrix[0].size()]) return;
    // 行
    int row = 0;
    int yaw =matrix[0].size();

    while(row<matrix.size() && yaw>=0)
    {
        if(matrix[row][yaw] < number ) row++;
        else if (matrix[row][yaw] > number ) yaw--;
        else return;
    }
    return;
}


int main()
{
    // n*n
//    vector<vector<int>> nums{{21,3},{2,5}};
    vector<vector<int>> nums{{1,2,3},{4,5,6},{7,8,9}};
    int seartchNumber = 5;

    searchMatrix2(nums,seartchNumber);

    return 0;
}