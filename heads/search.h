#ifndef SEARCH_H
#define SEARCH_H

#include <iostream>
#include <vector>

using namespace std;



/* -------------------------------------------
 * 顺序查找
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




#endif
