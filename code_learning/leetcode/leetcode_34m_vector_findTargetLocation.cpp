#include <iostream>
#include <vector>

using namespace std;

/* -------------------------------------------
 * 拆分查找
 * ------------------------------------------*/

vector<int> searchRange(vector<int> nums,int target)
{
    // 先二分法找到target所在下标 再对low high进行左右探索
    int low = 0;
    int high = nums.size()-1;
    int middle = (high+low)/2;
    bool sign = false; // 是否存在该目标

    // 找目标 是否存在target
    while(low<high)
    {
        int middle_ = (high+low)/2;
        if(nums[middle_] == target){
            sign = true;
            middle = middle_;
            break; // 进入到后面的左右探索
        }
        if(nums[middle_] < target){
            low = middle_ + 1;
        }
        else{
            high = middle_ - 1;
        }
    }

    high = middle + 1;
    low = middle - 1;
    // 找重复 确定该元素出现的频率
    while(sign)
    {
        if(nums[low] == nums[middle]) low -- ;
        if(nums[high] == nums[middle]) high++ ;
        if(nums[high] != nums[middle] && nums[low] != nums[middle] ) return vector<int>{low+1,high-1};
    }

    // 都没有
    return vector<int>{-1,-1};
}


int main()
{
    // 首先准备好nums target
    vector<int> nums{0,1,2,3,7,8,8,9};

    int target = 8;
    vector<int>result;
    result = searchRange(nums,target);

    return 0;
}