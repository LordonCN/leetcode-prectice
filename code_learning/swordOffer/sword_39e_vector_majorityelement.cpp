#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

/* -------------------------------------------
 *  ac 54 38
 *  这种简单题可以使用复杂度为n的遍历
 *  因为本题中要求出现频率超过一半的情况，所以可以参考下列解法：
 *  生成随机数选取法
 *  排序取中位数
 * ------------------------------------------*/
int majorityElement(vector<int>&nums)
{
    int thread = nums.size()/2+1;
    unordered_map<int,int>store;
    for(int i = 0;i<nums.size();i++)
    {
        store[nums[i]] += 1;
        if(store[nums[i]]==thread)return nums[i];
    }

    return 0;
}

int main()
{
    vector<int>temp {1,2,3,2,2,2,5,4,2,};
    majorityElement(temp);

    return 0;
}
