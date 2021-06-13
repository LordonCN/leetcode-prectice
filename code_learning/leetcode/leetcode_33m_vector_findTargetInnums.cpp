#include <iostream>
#include <vector>

using namespace std;

/* -------------------------------------------
 *
 * ------------------------------------------*/

int twoParts(vector<int> nums,int target)
{
    // 准备好 二分法前后指针
    int low = 0;
    int high = nums.size()-1;
    if(low == high) return -1;// 特殊情况

    while(low<=high)
    {
        int middle = (low+high)/2;
        // 找到位置 返回所在位置
        if(nums[middle] == target) return middle;
        // 存在两种情况:
        // 中间值小 并且在右半部分不存在更大的数 要左移  2 4 6 0 1 2 3 4 t=5
        if(nums[middle] < target && target > nums[high] ||
           // 中间值大 并且目标值小于当前区域最大值 要左移 1 3 4 7 0 1 t=2  
           nums[middle] > target && target > nums[high]){
           high = middle - 1;
        }
        else{
            low = middle + 1;
        }
    }
    return -1;
}

int search(vector<int>& nums, int target) {
    int l = 0, r = nums.size() -1;
    while (l <= r)
    {
        int mid = (l + r)/2;
        // 如果正好等于中间值
        if (target == nums[mid]) return mid;

        // mid划分出的左半区间为递增 包括第一次以及后面单调后的划分
        if (nums[l] <= nums[mid])  //中间值与最左侧比
        {   // target符合左半区间的值
            if (target >= nums[l] && target < nums[mid])
                r = mid-1;
            else
                l = mid+1;
        }
        else// mid 落在了右半区间
        {   // 符合右半区间的值
            if (target > nums[mid] && target <= nums[r])
                l = mid +1;
            else
                r = mid -1;
        }
    }
    return -1;
}

int main()
{
    // 首先准备好nums target
    vector<int> nums {7,9,0,1,2,3,7};

    int target = 5;
    int result;
    result = twoParts(nums,target);

    return 0;
}