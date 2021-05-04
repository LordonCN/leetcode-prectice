#include <iostream>
#include <vector>

using namespace std;

/* -------------------------------------------
 * 双指针移动 ac 55 67
 * ------------------------------------------*/

int removeDuplicates(vector<int>& nums) {
    if(nums.size()<3)return nums.size();
    // 双指针
    int l = 0,eachSum = 1;
    for(int r = 1;r<nums.size();r++)
    {
        if(nums[r] == nums[r-1] && eachSum < 2)//与前一个相等
        {
            eachSum ++;
            l++;
            nums[l] = nums[r];
        }
        else if(nums[r] == nums[r-1] && eachSum >= 2)// 跳过下一个
        {
            eachSum++;
        }
        else if(nums[r]!= nums[r-1])
        {
            l++;
            nums[l] = nums[r];
            eachSum = 1;
        }
    }
    return l+1;
}

int main()
{
    // 首先准备好nums target
    vector<int> nums {0,0,1,1,1,2,3,4,5,5,5,5,6,7,8};

    removeDuplicates(nums);

    return 0;
}