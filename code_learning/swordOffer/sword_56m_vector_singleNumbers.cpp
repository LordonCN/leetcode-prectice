#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*************************************************************************
 * 测试一下哈希表空间复杂度是多少 O(1) ac 44 9
 *======================================================================*/
void offer56(vector<int>&nums)
{
    // hash方法
    vector<int>resulthash;
    unordered_map<int,int>hash;
    for(int i : nums)
        hash[i] += 1;
    for(auto [c,v] : hash)
        if (v == 1) resulthash.push_back(c);

    return ;
}

int main()
{
    vector<int> nums{1,1,4,6,3,7,3,7};
    offer56(nums);

    return 0;
}