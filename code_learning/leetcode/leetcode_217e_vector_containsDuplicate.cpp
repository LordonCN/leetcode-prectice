#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

/* -------------------------------------------
 * ac 86.14%  30.43%
 * hash存储查找方法
 * ------------------------------------------*/
bool containsDuplicate1(vector<int> nums)
{
    unordered_map<int,int>hash;

    for(auto i : nums)
    {
        hash[i] += 1;
        if(hash[i] == 2)
            return true;
    }
    return false;
}

/* -------------------------------------------
 * ac 5.14%  77.43%
 * vector iterator find方法
 * ------------------------------------------*/
bool containsDuplicate(vector<int> nums)
{
    for(int i = 0;i<nums.size();i++)
    {
        vector<int>::iterator it = find(nums.begin()+i+1,nums.end(),nums[i]);
        if(it!=nums.end())
            return true;
    }
    return false;
}

int main()
{
    // 首先准备好nums target
    vector<int> nums{2,5,6,0,0,1};

    containsDuplicate(nums);

    return 0;
}