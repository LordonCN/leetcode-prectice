#include <iostream>
#include <vector>

using namespace std;


vector<int> twoParts(vector<int> nums,int target)
{
    // 先二分法找到target所在下标 再对low high进行左右探索
    int low = 0;
    int high = nums.size()-1;
    int middle = (high+low)/2;
    bool sign = false; // 是否存在该目标

    // 找目标
    while(low<=high)
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
    // 找重复
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
    vector<int> nums;
    nums.push_back(0);
//    nums.push_back(1);
//    nums.push_back(2);
//    nums.push_back(3);
//    nums.push_back(7);
//    nums.push_back(8);
//    nums.push_back(8);
//    nums.push_back(8);
//    nums.push_back(9);

    int target = 0;
    vector<int>result;
    result = twoParts(nums,target);

    return 0;
}