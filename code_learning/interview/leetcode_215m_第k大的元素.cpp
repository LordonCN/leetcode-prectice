#include <iostream>
#include <vector>

using namespace std;
/* -------------------------------------------
 * 题目介绍：查找第k大元素，目的是为了只对前k大元素进行排序，不是全排之后索引出来
 * 0、堆排 删除k-1次 【考察点】
 * 1、快排sort
 * ------------------------------------------*/

int sortWay = 2;
/* -------------------------------------------
 * STL sort
 * ------------------------------------------*/
bool sortCmp(const int a,const int b)
{
    return a < b; // 升序
}

/* -------------------------------------------
 * bubble sort
 * ------------------------------------------*/
void bubbleSort(vector<int> &nums)
{
    for(int low = 0; low < nums.size()-1; low++)
    {
        for(int high = low + 1; high < nums.size() ; high++)
        {
            if(nums[high]<nums[low])
                swap(nums[low],nums[high]);
        }
    }
}

/* -------------------------------------------
 * quick sort
 * ------------------------------------------*/
int partition(vector<int>&nums,int i,int j)
{
    int middleVal = nums[i];
    // stop when i == j
    while(i<j)
    {
        // swap left vector
        while(middleVal<nums[j] && j>i)
        {
            j -= 1;
        }
        if(j>i) swap(nums[i++],nums[j]);
        // swap right
        while(middleVal>nums[i] && j>i)
        {
            i += 1;
        }
        if(j>i) swap(nums[i],nums[j--]);
    }
    return i;

}

void quickSort(vector<int> &nums,int begin,int end)
{
    if(begin<end)
    {
        int mid = partition(nums,begin,end);
        quickSort(nums,0,mid-1); // begin == middle now
        quickSort(nums,mid+1,end);
    }

}

/* -------------------------------------------
 * heap sort
 * ------------------------------------------*/
int findKthLargest(vector<int>& nums, int k) {
    int length = nums.size();
    for(int i = length/2-1; i>=0; i--)// 找到中间位置 向前推
        makeheapGreat(nums,i,length);

    return sortHeap(nums,k);
}
void makeheapGreat(vector<int>&nums,int k,int length)
{
    for(int i = 2*k+1 ; i<length ; i = i*2+1)// 不仅包含交换 还有下坠处理 索引到节点的左孩子
    {
        if(i<length-1 && nums[i]<nums[i+1])  // 有两个叶子节点 且 右侧大于左侧
            i++;                             // i 指向当前孩子中最大的那个
        if(nums[k]<nums[i])                  // 如果子节点数值大于父节点 交换
            swap(nums[k], nums[i]);

        k = i;// 如果可下坠 更新孩子位置
    }
    return ;
}
int sortHeap(vector<int>&nums,int k)
{
    for(int i = nums.size()-1;i>0;i--)
    {
        k--;
        if(k == 0)break;
        if(nums[0]>nums[i])// 堆顶与末尾的交换
        {
            swap(nums[0],nums[i]);// 大根堆顶与最后数字进行交换
            makeheapGreat(nums, 0, i-1);// 除交换的最后一个外重新排列一下位置
        }

    }
    return nums[0];
}



void findKthNumber(vector<int> &nums,int K)
{
    if(nums.size()<2)
        return;
    switch(sortWay)
    {
        case 1:
            sort(nums.begin(),nums.end(),sortCmp);
            break;
        case 2:
            bubbleSort(nums);
            break;
        case 3:
            quickSort(nums,0,nums.size()-1);
            break;
        default:
            break;
    }
    cout<<nums[K]<<endl;
}

int main()
{
    // 首先准备好nums target
    vector<int> nums {0,4,1,6,9,8,13};

    int k = 3;
    findKthNumber(nums,k);

    return 0;
}