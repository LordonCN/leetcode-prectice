#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

/* -------------------------------------------
 * hashset 细节补充
 * 重点：
 * set.insert 插入新元素
 * set.empty 是否为空
 * set.count 判断是否有该元素
 * set.erase 清除某个元素
 * max 统计最大值 一直用不好 注意一下
 * ------------------------------------------*/

int twoSum(vector<int>& nums)
{
    int result;
    unordered_set<int>hashset;

    // 时间复杂度为n 的集合创建
    for(const auto number:nums)
        // 集合中插入新元素
        hashset.insert(number);

    // length
    int length = 1;
    // 集合没有遍历完
    while(!hashset.empty())
    {
        // 首先取集合中国第一个数 不管大小 寻找比它小1的数 若有则清除 若没有则统计长度
        int curvalue = *(hashset.begin());
        hashset.erase(curvalue);
        int dcur = curvalue -1 ,icur = curvalue+1;
        // 若集合中存在此元素 统计个数
        while(hashset.count(dcur))
        {
            hashset.erase(dcur);
            dcur -= 1;
        }
        while(hashset.count(icur))
        {
            hashset.erase(icur);
            icur += 1;
        }
        result = max(result,icur-dcur-1);
    }

    return result;
}

int main()
{
    // 首先准备好nums target
    vector<int> nums {7,9,1,0,1,2,8};
    int target = 10;

    twoSum(nums);

    return 0;
}