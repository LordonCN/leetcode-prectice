#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

/* -------------------------------------------
 * 亮点：
 * 使用accumelate迭代器计算vector sum
 * accumulate(a.begin(),a.end(),0)
 * ------------------------------------------*/
#include <stack>
#include <math.h>
int countD(int mid,const vector<int>nums)
{
    int day = 1;
    int sum = nums[0];
    for(int i = 1;i<nums.size();i++)
    {
        if(sum<=mid-nums[i])
            sum += nums[i];
        else
        {
            day+=1;
            sum = nums[i];
        }

    }
    return day;
}

int main()
{
    vector<int>nums{10,50,100,100,50,100,100,100};
    int target = 5;

    int minD = *max_element(nums.begin(),nums.end());// 天数最长应该每天运最多的那个量
    int maxD = accumulate(nums.begin(),nums.end(),0);// 天数最短要运所有的量
    int midD ;
    while(minD<maxD)
    {
        midD = (minD+maxD)/2;
        int days = countD(midD,nums);
        if(days > target)// 只有大了才会增加下限 否则减少上线求最小值
            minD = midD+1;
        else
            maxD = midD;
    }
    cout<<midD;

    return 0;

}
