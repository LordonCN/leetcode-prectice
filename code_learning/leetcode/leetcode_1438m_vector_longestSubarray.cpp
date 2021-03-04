#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

/*************************************************************************
 * 暴力破解法 超出时间限制 ac 5 87 添加如果从当前位置遍历到最后了可直接结束
 * 队列实现 辅助以两个栈 时间复杂度为n 空间复杂度大一点
 *======================================================================*/
void leetcode1438(vector<int>&nums,int limit)
{

    int maxlength = 0;
    vector<int>result;

    for(int i = 0 ; i < nums.size();i++)
    {
        result.push_back(nums[i]);
        int minnumber = nums[i];
        int maxnumber = nums[i];
        for(int t = i+1 ; t < nums.size();t++)
        {
            minnumber = min(minnumber,nums[t]);
            maxnumber = max(maxnumber,nums[t]);

            if(abs(maxnumber - minnumber)<=limit)
            {
                result.push_back(nums[t]);
                int lengthnow = result.size();
                maxlength = max(maxlength,lengthnow);

                if(maxlength == nums.size()-i)return ;
            }
            else
            {
                break;
            }
        }
        result.erase(result.begin(),result.end());
    }
//    if(maxlength == 0)
//        return 1;
//    else
//        return maxlength;
    return ;
}

int main()
{
    // 首先准备好nums target
    vector<int> nums {1,3,-1,-3,5,3,6,7};
    int limit = 2;
    leetcode1438(&nums,limit)

    return 0;
}