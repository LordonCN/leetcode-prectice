#include <iostream>
#include <vector>
#include "sort.h"

using namespace std;

/* -------------------------------------------
 * insertsort
 * 关键就是搞清楚从前向后判断的长度逐次减少
 * ------------------------------------------*/
vector<int> insertsort(vector<int>&nums)
{
    for(int i = 0;i<nums.size();i++)
    {
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
    vector<int> result = insertsort(nums);


    return 0;
}