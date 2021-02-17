#include <iostream>
#include <vector>

using namespace std;

/* -------------------------------------------
 * 拆分查找 折半查找
 * ------------------------------------------*/
bool searchRota(vector<int> nums,int target)
{
    int low = 0;
    int high = nums.size()-1;

    while(low<=high)
    {
        int mid = (high+low)/2;
        if(nums[mid] == target) return true;
        // 取右侧
        if(nums[mid]<=nums[high])
        {
            if(nums[mid] < target && nums[high]>=target){
                low = mid +1;
            }
            else{
                high = mid - 1;
            }
        }
        else
        {
            if(nums[mid] > target && nums[low]<=target){
                high = mid - 1;
            }
            else{
                low = mid +1;
            }
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