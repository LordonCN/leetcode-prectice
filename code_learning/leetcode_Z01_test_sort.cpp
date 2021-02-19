#include <iostream>
#include <vector>
#include "sort.h"

using namespace std;

/* -------------------------------------------
 * mergesort
 * ------------------------------------------*/
vector<int> mergesort(vector<int>&nums,int l,int r)
{
    if(l>=r-1) return nums; //直到分解成只有一个元素
    //1、首先进行拆分
    int mid = (l+r)/2;
    mergesort(nums,l,mid);
    mergesort(nums,mid,r);
    //TODO:2、合并操作

    return nums;
}

int main()
{
    // 首先准备好nums target
    vector<int> nums{7,2,9,4,8,10,1};
    int l = 0,r = nums.size()-1;
    vector<int> result = quicksort(nums,l,r);
//    vector<int> result = mergesort(nums,l,r);



    return 0;
}