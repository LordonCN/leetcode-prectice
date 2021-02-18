#ifndef SORT_H
#define SORT_H
#include <iostream>
#include <vector>

using namespace std;

/* -------------------------------------------
 * 汇总所有排序方法 方便使用与复习
 * ------------------------------------------*/

/* -------------------------------------------
 * bubblesort
 * 关键就是搞清楚从前向后判断的长度逐次减少
 * ------------------------------------------*/
vector<int> bubblesort(vector<int>&nums)
{
    int length = nums.size();
    while(--length)
    {
        for(int i = 0 ;i<length;i++)// 截止到前一项 因为有i+1
        {
            if(nums[i]>nums[i+1]) swap(nums[i],nums[i+1]);
        }
    }
    return nums;
}

/* -------------------------------------------
 * quicksort
 * 分解 治理 合并阶段
 * 首先选取参考元素
 * 在while中对比左右两侧值大小 右侧比value大的不动 last左移 直到发现小值或超范围
 * 发现小值则交换 并对左侧位置大值进行寻找 找到大值或者超范围 交换
 * ------------------------------------------*/
vector<int> quicksort(vector<int>&nums,int l,int r)
{
    // 分解 找基准元素
    int value = nums[l],mid,first = l,last = r ;
    if(l<r)
    {
        while(first<last)
        {
            // 左侧值大 移动last寻找小值 与右侧小值交换
            while(first<last && nums[last]>=value)
                last--;
            // 左侧first数值比last数值大 交换并右移first
            if(first<last)
                swap(nums[first++],nums[last]);

            while(first<last && nums[first]<=value)
                first++;
            if(first<last)
                swap(nums[first],nums[last--]);
        }
        mid = first;
        quicksort(nums,l,mid-1);
        quicksort(nums,mid+1,r);
    }
    return nums;
}





#endif