#include <iostream>
#include <vector>

using namespace std;
/*************************************************************************
 * 一维数组计算思路
 * dp思路 ac 39 14
 *======================================================================*/
int maxProfit(vector<int>& nums)
{
    vector<int>result(nums.size(),0);
    int minInput = nums[0];

    for(int i = 1;i<nums.size();i++)
    {
        if(nums[i]<minInput)minInput =nums[i];
        if(nums[i]-minInput>result[i-1])
            result[i] = nums[i] - minInput;
        else
            result[i] = result[i-1];
    }
    return result[nums.size()-1];
}
/*************************************************************************
 * 二维数组计算速度满了 存储上升了
 * 但是二维通用性强
 * dp思路 ac 5 5
 *======================================================================*/
void methord121_2(vector<int>& nums)
{
    vector<vector<int>>result(nums.size(),vector<int>(2,0));
    result[0][0] = 0;
    result[0][1] = -nums[0];

    for(int i = 1;i<nums.size();i++)
    {
        result[i][0] = max(result[i-1][0],result[i-1][1]+nums[i]);
        result[i][1] = max(result[i-1][1],-1 * nums[i]);
    }
    return ;
}

int main()
{
    vector<int>nums{7,1,2,5,4,7,5};
    maxProfit(nums);
    return 0;
}