#include <iostream>
#include <vector>
#include "sort.h"

using namespace std;

/* -------------------------------------------
 * mergesort
 * ------------------------------------------*/
vector<int> mergesort(vector<int>&nums)
{
    for(int i = 0;i<nums.size()-1;i++)
    {
        int mid = i;
        for(int j = i+1;j<nums.size();j++)
        {
            if(nums[mid]>nums[j])
                mid = j;
        }
        swap(nums[mid],nums[i]);

    }
    return nums;
}

int main()
{
    // 首先准备好nums target
    vector<int> nums{7,2,9,4,8,10,1};
    // quicksort
//    int l = 0,r = nums.size()-1;
//    vector<int> result = quicksort(nums,l,r);

    // bubblesort
    vector<int> result = mergesort(nums);


    return 0;
}