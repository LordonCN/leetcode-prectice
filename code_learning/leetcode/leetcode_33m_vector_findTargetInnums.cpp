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
    if(low == high) return -1;

    while(low<=high)
    {
        int middle = (low+high)/2;
        // 找到位置 返回所在位置
        if(nums[middle] == target) return middle;
        // 中间值小 并且在右半部分不存在更大的数 要左移
        if(nums[middle] < target && target > nums[high] ||
           // 中间值大 并且目标值小于当前区域最大值 要左移
           nums[middle] > target && target < nums[middle]){

            high = middle - 1;
        }
        else{
            low = middle + 1;
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