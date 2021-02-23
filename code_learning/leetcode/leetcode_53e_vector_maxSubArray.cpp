#include <iostream>
#include <vector>

using namespace std;

/* -------------------------------------------
 * 动态规划 O(n)
 * 贪心 O(n2)
 * 可以用分治 就是参数有点多 先不考虑
 * ------------------------------------------*/
int maxSubArrayTanxin(vector<int> nums)
{
    int maxnumber = nums[0];
    int sumNow = 0;
    for(int i = 0; i < nums.size();i++)
    {
        sumNow = nums[i] ;
        for(int t = i+1;t <nums.size();t++)
        {
            maxnumber = max(maxnumber,sumNow);
            sumNow += nums[t];
        }
        maxnumber = max(maxnumber,sumNow);
    }
    return maxnumber;
}


//{-2,1,-3,4,-1,2,1,-5,4};
int maxSubArrayDynamic(vector<int> nums)
{
    if(nums.size()<2) return nums[0];
    int maxnumber = nums[0];
    int sumNow = 0;
    for(int i = 0; i < nums.size();i++)
    {
        sumNow += nums[i];
        maxnumber = max(maxnumber,sumNow);
        if(sumNow<0) sumNow = 0;// 关键点这里描述为对整个的贡献可行度
    }
    return maxnumber;
}


int main()
{
    vector<int> nums {-2,1,-3,4,-1,2,1,-5,4};

    int result;
//    result = maxSubArrayTanxin(nums);
    result = maxSubArrayDynamic(nums);

    return 0;
}