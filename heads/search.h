#ifndef SEARCH_H
#define SEARCH_H

#include <iostream>
#include <vector>

using namespace std;

/* -------------------------------------------
 * 顺序查找
 * 无序 有序均可
 * 有序可以提前终止
 * ------------------------------------------*/
int searchSeq(vector<int>&nums,int k)
{
    vector<int>::iterator ite = nums.begin();
    while(ite != nums.end())
    {
        if(*ite == k) return ite-nums.begin();
        else
            ite++;
    }
    return -1;
}

/* -------------------------------------------
 * 二分查找
 * 有序查找
 * ------------------------------------------*/
int binartSearch(vector<int>&nums,int key)
{
    int left = 0;
    int right = static_cast<int>(nums.size()-1);

    while(left < right)
    {
        int mid = (right+left)/2;
        if(key == nums[mid])
            return mid;
        else if(key > nums[mid])
            left = mid+1;
        else
            right = mid-1;
    }
    return -1;
}


#endif
