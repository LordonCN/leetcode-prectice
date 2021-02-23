#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

/* -------------------------------------------
 * 参考：https://zhuanlan.zhihu.com/p/100994146?utm_source=wechat_session&utm_medium=social&utm_oi=817728191245488128
 * 注意:
 * 使用类似于516题的二维解法并`不能够`推出状态转移方程
 * 0 8 8 8 8 8 8
 *   8 8 8 8 8 8
 *     1 2 5 5 5
 *       2 5 5 5
 *         5 4 7
 *           4 7
 *             7 此处不适用
 *
 * 使用一维数组 这种遍历方法t始终<i 内循环在左侧
 * ------------------------------------------*/
int longestXulie(vector<int>nums)
{
    // base case
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