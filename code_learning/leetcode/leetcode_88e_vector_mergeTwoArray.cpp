#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

/* -------------------------------------------
 * 双指针
 * ------------------------------------------*/

void twoSum(vector<int>& nums,int m,vector<int>& nums1,int n)
{

    int numsP = m-1,nums1P = n-1,pos = m+n-1;
    while(numsP>=0 && nums1P>=0)
    {
        nums[pos--] = nums[numsP] > nums1[nums1P] ? nums[numsP--] : nums1[nums1P--];
    }

    // 若第二个没遍历完 则要单独继续复制 第一个没遍历完可以直接退出 因为本来就是排好顺序的
    while(nums1P>=0)
    {
        nums[pos--] = nums1[nums1P--];
    }


    return ;
}

int main()
{
    // 首先准备好nums target
    vector<int> nums {1,2,3,0,0,0};
    vector<int> nums1 {2,5,6};


    twoSum(nums,3,nums1,3);

    return 0;
}