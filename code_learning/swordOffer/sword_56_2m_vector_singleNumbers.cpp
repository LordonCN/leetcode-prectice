#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*************************************************************************
 * 第二题 ac 89 84 3.4
 *======================================================================*/
void offer56_2(vector<int>&nums)
{
    vector<int>resultsort;
    sort(nums.begin(),nums.end());
    for(int i = 0 ;i<nums.size()-2;i++)
    {
        if(nums[i] == nums[i+1])
            i += 2;
        else
        {
            resultsort.push_back(nums[i]);
            break;
        }
    }
    if(resultsort.empty())
        resultsort.push_back(nums[nums.size()-1]);

    return ;
}

int main()
{
    vector<int> nums{3,4,3,4,1,4,3};

    offer56(nums);

    return 0;
}