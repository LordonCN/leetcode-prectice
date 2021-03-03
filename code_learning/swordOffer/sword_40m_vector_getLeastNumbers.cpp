#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*************************************************************************
* offer40 ac 84 79 3.3
*======================================================================*/
vector<int> offer40(vector<int>& nums,int k)
{
    vector<int>result;
    sort(nums.begin(),nums.end());
    int i = 0;
    while(i<k)
    {
        result.push_back(nums[i++]);
    }
    return result;
}

int main()
{
//    vector<vector<int>> nums{{21,3},{2,5}};
    vector<int> nums{1,2,3,40,46,42,5,6,7,8,9};
    int k = 2;

    findNumberIn2DArray(nums,k);

    return 0;
}