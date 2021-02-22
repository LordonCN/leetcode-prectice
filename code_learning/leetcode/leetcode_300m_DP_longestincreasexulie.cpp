#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

/* -------------------------------------------
 * https://zhuanlan.zhihu.com/p/100994146?utm_source=wechat_session&utm_medium=social&utm_oi=817728191245488128
 * 注意:
 * 类似于516题
 * 0 8 8 8 8 8 8
 * 0 8 8 8 8 8 8
 * 0 1 1 2 5 5 5
 * 0 0 1 2 5 5 5
 * 0 0 1 2 5 4 7
 * 0 0 1 2 4 4 7  从下往上横向遍历
 * 0 0 1 2 4 7 7
 *
 * 0 1 1 3 3 3
 * 1 1 1 3 3 3
 * 0 0 0 3 3 3
 * 3 3 3 3 3 3
 * 2 2 2 2 2 3
 * 3 3 3 3 3 3
 *
 * 0,1,0,3,2,3
 * 2 1 1 1 1 1
 * ------------------------------------------*/
int longestXulie(vector<int>nums)
{
    vector<int>dp(nums.size(),1);

    for(int i = 0;i<nums.size();i++)
    {
        for(int t = 0;t<i;t++)
        {
            if(nums[t] < nums[i])
                dp[i] = max(dp[t]+1,dp[i]);
        }
    }

    return 0;
}

int main()
{
    vector<int>nums {0,1,0,3,2,3};
    longestXulie(nums);
    return 0;
}