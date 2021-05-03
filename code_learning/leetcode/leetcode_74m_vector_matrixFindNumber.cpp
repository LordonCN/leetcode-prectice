#include <iostream>
#include <vector>
using namespace std;

/* -------------------------------------------
 * 思路：
 * 从右上便利到左下 ac 34 84
 * ------------------------------------------*/
bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int row = 0;
    int yaw = matrix[0].size()-1;
    while(yaw >=0 && row <= (matrix.size()-1))
    {
        if(matrix[row][yaw]<target) row++;
        else if(matrix[row][yaw] > target) yaw--;
        else return true;
    }
    return false;
}

int main()
{
    vector<vector<int>>matrix{{1,3,5,7},{10,11,16,20},{23,30,34,60}};
    searchMatrix(matrix);
    return 0;
}
