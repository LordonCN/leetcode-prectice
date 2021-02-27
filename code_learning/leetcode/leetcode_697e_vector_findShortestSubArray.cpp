#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

/* -------------------------------------------
 * ac 8785%  64.5%
 * hash存储查找方法
 * ------------------------------------------*/
int findShortestSubArray(vector<int> nums)
{
    unordered_map<int,int>hash,firstPos;
    int degree = 0,length = INT16_MAX-1;

    for(int i = 0;i<nums.size();i++)
    {
        // 记录数字第一次出现的位置 以及次数统计
        if(firstPos.count(nums[i]) == 0)
        {
            firstPos[nums[i]] = i;
        }

        // 判断度的大小 大于的时候直接取长度
        if(++hash[nums[i]]>degree)
        {
            degree = hash[nums[i]];
            length = i-firstPos[nums[i]]+1;
        }
        else if(hash[nums[i]] == degree)// 只有相同度下才会比较最小长度
        {
            length = min(length,i-firstPos[nums[i]]+1);
        }
    }
    return length;
}


int main()
{
    // 首先准备好nums target
    vector<int> nums{2,5,6,5,6,6,1};

    findShortestSubArray(nums);

    return 0;
}