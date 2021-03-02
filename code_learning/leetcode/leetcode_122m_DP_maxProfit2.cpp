#include <iostream>
#include <vector>

using namespace std;
/*************************************************************************
 * dp思路 ac 7.68 5.07
 *======================================================================*/
int methord122(vector<int>& nums)
{
    vector<vector<int>>result(nums.size(),vector<int>(2,0));
    result[0][0] = 0;
    result[0][1] = -nums[0];

    for(int i = 1;i<nums.size();i++)
    {
        result[i][0] = max(result[i-1][0],result[i-1][1]+nums[i]);
        result[i][1] = max(result[i-1][1],result[i-1][0]-nums[i]);
    }
    return result[nums.size()-1][0];
}

int main()
{
    vector<int>nums{7,1,2,5,4,7,5};
    maxProfit(nums);
    return 0;
}