#include <iostream>
#include <vector>

using namespace std;

/* -------------------------------------------
 * 最大可到达下标与当前位置进行比较 
 * 与可到达位置进行比较
 * ------------------------------------------*/
bool canJump(vector<int>& nums) {
    int maxNumber = 0;
    int length = nums.size();
    for(int i = 0;i<length;i++)
    { // 考虑到直到索引大于能到的最大值 所以遍历到最后一个
        if(i>maxNumber)return false;
        maxNumber =max(maxNumber, nums[i] + i);
    }
    return true;

}

bool canJump2(vector<int>& nums) {
    int maxNumber = 0;
    int length = nums.size();

    for(int i = 0;i<length-1;i++)
    { 
        maxNumber =max(maxNumber, nums[i] + i);
        if(maxNumber <= i)return false;
    }
    return true;
}
int main()
{
    vector<int>nums{1,0,1,0};
    canJump2(nums);
    return 0;
}