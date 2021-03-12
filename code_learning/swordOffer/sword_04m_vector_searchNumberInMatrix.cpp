#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/* -------------------------------------------
 * 思路：
 * 1、首先竖着判断位于第几行 再横着搜看是否存在对应值
 * 2、从右上角开始判断大小 向下向左移动即可
 * ------------------------------------------*/
bool findNumberIn2DArray(vector<vector<int>>& matrix, int number) {
    if(matrix.empty() || matrix[0].size()==0)return false;
    if(number<matrix[0][0]) return false; //小于最小值
    if(number>matrix[matrix.size()-1][matrix[0].size()-1]) return false;// 大于最大值
    int row = matrix[0].size()-1;// 列
    int hang = 0;
    while(row>=0 && hang<matrix.size())// 在范围内的时候
    {
        if(number<matrix[hang][row])
            row -= 1;
        else  if(number>matrix[hang][row])
            hang += 1;
        else if(number == matrix[hang][row])
            return true;
        else return false;
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