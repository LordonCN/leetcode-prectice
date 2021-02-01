#include <iostream>
#include <vector>

using namespace std;

/* -------------------------------------------
 * 双指针移动
 * ------------------------------------------*/

void maxArea(vector<int> nums)
{
    int maxWaterArea = 0;
    int front = 0,back = nums.size()-1;
    while(front != back)
    {
        maxWaterArea = max(maxWaterArea,min(nums[front],nums[back])*(back-front));

        if(nums[front]<= nums[back])
        {
            front ++;
        }
        else
        {
            back --;
        }
    }

    return ;
}


int main()
{
    // 首先准备好nums target
    vector<int> nums {7,9,0,1,2,3,7,2,3};

    maxArea(nums);

    return 0;
}