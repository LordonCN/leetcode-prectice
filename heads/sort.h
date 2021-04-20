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
vector<int> selectSort(vector<int>&nums)
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
vector<int> insertSort(vector<int>&nums)
{
    for(int i = 0;i<nums.size();i++)//所排序长度逐渐增加
    {
        for(int j = i; j > 0 ;--j) // 如果把判断条件写到循环里会进行无意义的判断
        {
            if( nums[j] < nums[j-1])
                swap(nums[j],nums[j-1]);
            else
                break;
        }

    }
    return nums;
}

/* -------------------------------------------
 * 希尔排序 在插入基础上添加步长操作
 * 4.17
 * ------------------------------------------*/
vector<int> shellSort(vector<int>&nums)
{
    int m = nums.size()/2;
    for(int k = m;k>=1;k/=2)// 设定步长
    {
        for(int i = 0;i<nums.size()/k;i++)//按照步长增加 注意/k 遍历的数字逐渐增多
        {
            for(int j = i; j-k>= 0 ;j-=k)// 这里如果不判断j-k的大小会索引错误 或者在if中判断是否有j-k>0
            {
                if(nums[j] < nums[j-k])
                    swap(nums[j],nums[j-k]);
                else
                    break;
            }
        }

    }
    return nums;
}
/* -------------------------------------------
 * bubblesort     n2  稳定
 * 遇到大值就向后移动 将前面最大的数放到当前循环的最后
 * 关键就是搞清楚从前向后判断的长度逐次减少
 * ------------------------------------------*/
vector<int> bubbleSort(vector<int>&nums)
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
vector<int> quickSort(vector<int>&nums,int l,int r)
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
        if(first<mid) quickSort(nums,first,mid-1);
        if(last>mid) quickSort(nums,mid+1,last);
    }
    return nums;
}

/* -------------------------------------------
 * 归并排序
 * 分治思想
 * 4.15测试 4.17复习
 * 4.19 r-l+1  &&
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

    int mid = left + (right - left) / 2;// (left+right)/2
    MergeSort(nums, left, mid);
    MergeSort(nums, mid + 1, right);
    Merge(nums, left, right, mid);
}

/* -------------------------------------------
 * 堆排序
 * 4.17 大根堆方法
 * 易混点：长度怎么给的问题 得画图分析
 * ------------------------------------------*/
void makeheapGreat(vector<int>&nums,int k,int length)
{
    for(int i = 2*k+1;i<length;i = i*2+1)// 不仅包含交换 还有下坠处理
    {
        if(i<length-1 && nums[i]<nums[i+1])// 有两个叶子节点
            i++;// 取大的那个
        if(nums[k]<nums[i])
            swap(nums[k], nums[i]);
        k = i;// 如果可下坠 更新孩子位置
    }
    return ;
}

void sortHeap(vector<int>&nums)
{
    for(int i = nums.size()-1;i>0;i--)
    {
        if(nums[0]>nums[i])// 堆顶与末尾的交换
        {
            swap(nums[0],nums[i]);// 大根堆顶与最后数字进行交换
            makeheapGreat(nums, 0, i-1);// 除交换的最后一个外前边部分进行大根堆重排
        }
    }
    return;
}

void heapSort(vector<int>&nums,int length)
{
    for(int i = length/2-1 ; i>=0 ; i--)// 找到中间位置 向前推
        makeheapGreat(nums,i,length);
    sortHeap(nums);
    return;
}

/* -------------------------------------------
 * 基数排序
 * 先从const int i说起。使用const修饰的i我们称之为符号常量。即，i不能在其他地方被重新赋值了。
 * 注意：const int i与int const i是等价的，相同的，即const与int的位置无所谓。
 * pos = 0, 表示个位数 pos = 1, 表示十位数 pos = 2, 表示百位数 其中new_type为要转换的数据类型，expression为原始的变量或表达式
 * ------------------------------------------*/
#include <math.h>
void bucketSort(vector<int> & nums)
{
    const int bucketSize= 10;               //定义桶数组长度
    vector<vector<int>> buckets(bucketSize);//二维的桶数组长度，有BUCKETS行，每行元素都是空

    //外层循环是根据数字的位数确定的。因为是三位数，所以从2到0
    for (int pos = 0; pos <= 2; ++pos)
    {
        // 放到桶里
        int denominator = static_cast<int>(pow(10, pos)); // 取某一位数的时候需要用的分母  pow(10, pos)；10是底数，pos是指数
        for (auto tmp : nums)               // 按数字放入桶中
            buckets[(tmp / denominator) % 10].push_back(tmp);//按照个位数大小放置桶的位置，十位、百位也是如此

        // 从桶中取出来，放入原来的nums序列中，以备下次遍历时使用
        int index = 0;
        for (auto &theBucket : buckets)     //为什么用auto&而不是auto；theBucket是个引用，改变theBucket，影响buckets的值
        {
            for (int &k : theBucket)
                nums[index++] = k;
            theBucket.clear();              //一定要清空桶中数据 但是空间并没有释放
        }
    }
}

#endif