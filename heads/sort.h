#ifndef SORT_H
#define SORT_H
#include <iostream>
#include <vector>

using namespace std;

/* -------------------------------------------
 * selectsort     n2  不稳定
 * 两次循环 内环通过比较大小得到
 * `当前剩余的最小值下表`
 * 与最前面的索引进行交换
 * ------------------------------------------*/
vector<int> selectsort(vector<int>&nums)
{
    for(int i = 0;i<nums.size()-1;i++)// 关键是到倒数第二项
    {
        int mid = i;
        for(int j = i+1;j<nums.size();j++)
        {
            if(nums[mid]>nums[j])
                mid = j;
        }
        swap(nums[mid],nums[i]);

    }
    return nums;
}

/* -------------------------------------------
 * insertsort     n2  稳定
 * 感觉像反向冒泡 气泡从上面开始冒出 底下的最后冒出
 * 关键就是搞清楚从前向后判断的长度逐次增加
 * ------------------------------------------*/
vector<int> insertsort(vector<int>&nums)
{
    for(int i = 0;i<nums.size();i++)//所排序长度逐渐增加
    {
        for(int j = i; j > 0 && nums[j] < nums[j-1];--j) // 将最小值放到当前排序长度的最后  j-- --j有啥区别吗
            swap(nums[j],nums[j-1]);
    }
    return nums;
}

/* -------------------------------------------
 * bubblesort     n2  稳定
 * 遇到大值就向后移动 将前面最大的数放到当前循环的最后
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
 * 首先选取参考元素 当前[l,r]最左值
 * 在while中对比左右两侧值大小
 * 右侧比value大的不动 r左移 直到发现小值或超范围 将其交换 value到r位置
 * 并对左侧l大值进行寻找 找到大值或者超范围 交换
 * 3.29第一遍默写把mid既当做了value 又当做了范围缩引来用
 * ------------------------------------------*/
vector<int> quicksort(vector<int>&nums,int l,int r)
{
    int mid,first = l,last = r ;
    if(first<last)
    {
        int value = nums[first];// 找基准元素
        while(l<r)
        {
            // 左侧值大 移动last寻找小值 与右侧小值交换
            while(l<r&& nums[r]>=value)
                r--;
            // 左侧first数值比last数值大 交换并右移first
            if(l<r)
                swap(nums[l++],nums[r]);

            while(l<r&& nums[l]<=value)
                l++;
            if(l<r)
                swap(nums[l],nums[r--]);
        }
        mid = l;
        if(first<mid) quicksort(nums,first,mid-1);
        if(last>mid) quicksort(nums,mid+1,last);
    }
    return nums;
}





#endif