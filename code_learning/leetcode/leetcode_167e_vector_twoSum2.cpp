#include <iostream>
#include <vector>

using namespace std;

/* -------------------------------------------
 * 亮点：
 * return vector<int>{a,b}
 * ------------------------------------------*/

vector<int> twoSum(vector<int>& nums,int target)
{
    vector<int>result;
    int l = 0,r = nums.size()-1;
    int sum = 0;

    while(l<r)
    {
        sum = nums[l] + nums[r];
        if(sum<target)l++;
        else if(sum>target)r++;
        else return vector<int>{l,r}; //返回下标
    }
}

int main()
{
    // 首先准备好nums target
    vector<int> nums {0,1,2,7,9};
    int target = 10;

    twoSum(nums,target);

    return 0;
}