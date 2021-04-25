#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

/* -------------------------------------------
 * 根据一行或一列数字中同一数字出现频率来判断 用map hashmap.clear();
 * 难点在于搞清楚遍历的层次顺序
 * 3*3 就存在四层循环嵌套
 * ------------------------------------------*/

int firstMissingPositive(vector<int>& nums) {
    sort(nums.begin(),nums.end());
    for(int i = 1;i<303;i++)
    {
        if(find(nums.begin(),nums.end(),i) == nums.end())
            return i;
    }
    return 0;

}

int main()
{
    vector<int>nums{1,2,3,6,7,8};

    firstMissingPositive(nums);

    return 0;
}