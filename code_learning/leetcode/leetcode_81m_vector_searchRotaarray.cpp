#include <iostream>
#include <vector>

using namespace std;

/* -------------------------------------------
 * 拆分查找 折半查找
 * 关键点：
 * 特殊类型判定【重复数字太多的】
 * 不确定单调性时的左右区间判断，说明折半查找必须要有`明显的单调性存在` 否则毫无办法 先sort
 * ------------------------------------------*/
bool searchRota(vector<int> nums,int target)
{
    int low = 0;
    int high = nums.size()-1;

    while(low<=high)
    {
        int mid = (high+low)/2;
        if(nums[mid] == target) return true;
        if(nums[min] == nums[low]) low++;// [1,1,1,1,1,2,1,1] 这个最难想
        // 若中间值要比最右侧小 说明右侧单调 若相等则说明存在重复
        // 取右侧部分
        else if(nums[mid]<=nums[high])
        {
            // 通过两端值判断确定目标值是否在右侧
            if(nums[mid] < target && nums[high]>=target){
                // 取右侧折半
                low = mid +1;
            }
            else high = mid - 1;
        }
        else
        {
            if(nums[mid] > target && nums[low]<=target){
                high = mid - 1;
            }
            else low = mid +1;
        }
    }
    return false;
}


int main()
{
    // 首先准备好nums target
    vector<int> nums{2,5,6,0,0,1,2};

    int target = 6;
    searchRota(nums,target);

    return 0;
}