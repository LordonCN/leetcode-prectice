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
        for(int j = i; j > 0 && nums[j] < nums[j-1];--j) // 将最小值放到当前排序长度的最后  j-- --j有啥区别吗 在循环中的这个位置并没有区别 相当于单独执行了一条语句 都是发生了变化 但是在判断条件中还是真实情况下都是有特殊含义的
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

/* -------------------------------------------
 * 归并排序
 * 分治思想
 * 4.15测试 4.17复习
 * ------------------------------------------*/
void Merge(vector<int>& nums, int left, int right, int mid)
{
    int i = left;
    int j = mid + 1;

    int k = 0;
    vector<int> temp(right - left + 1, 0);

    // 小范围排序存放到temp
    while (i <= mid && j <= right)// 想清楚为啥
    {
        if (nums[i] < nums[j])    // 易混
            temp[k++] = nums[i++];
        else
            temp[k++] = nums[j++];
    }
    while (i <= mid)
        temp[k++] = nums[i++];

    while (j <= right)
        temp[k++] = nums[j++];

    // 将小部分排好序的放回nums
    k = 0;
    for (i = left; i <= right; i++)
        nums[i] = temp[k++];
    return;
}

void MergeSort(vector<int>& nums, int left, int right)
{
    if (left >= right)
        return;

    int mid = left + (right - left) / 2;
    MergeSort(nums, left, mid);
    MergeSort(nums, mid + 1, right);
    Merge(nums, left, right, mid);
}

/* -------------------------------------------
 * 堆排序
 * 4.17 测试
 * ------------------------------------------*/
void heapSortGreat(vector<int>&nums,int k,int length)
{
    for(int i = 2*k+1;i<=length;i = i*2+1)// 这里为了下坠处理
    {
        if(i<length && nums[i]<nums[i+1])
            i++;// 取大的那个 否则还是单节点
        if(nums[k]<nums[i])swap(nums[k], nums[i]);
        k = i;// 更新孩子位置下坠检测
    }
    return ;
}

void heapSortLess(vector<int>&nums,int k,int length)
{
    for(int i = 2*k+1;i<=length;i = i*2+1)// 这里为了下坠处理
    {
        if(i<length && nums[i]>nums[i+1])
            i++;
        if(nums[k]>nums[i])swap(nums[k], nums[i]);
        k = i;
    }
    return ;
}

void buildHeap(vector<int>&nums,int length)
{
    for(int i = length/2-1 ; i>=0 ; i--)// 这里是因为从0开始的 所以减一
        heapSortLess(nums,i,length);
//        heapSortGreat(nums,i,length);
    return;
}



#endif