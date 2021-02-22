#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

/* -------------------------------------------
 * https://zhuanlan.zhihu.com/p/100994146?utm_source=wechat_session&utm_medium=social&utm_oi=817728191245488128
 * 注意:
 * 最长回文子序列与最长回文子字符串的区别
 * 子序列是指字符串中从左到右的字符序列 可以不连续 使用动态规划
 * 子字符串是指字符串中从左到右的连续字符 必须连续 用reverse(vector)可以方便判断
 * 1 1 3 3 3 3 3 3 5 5
 *   1 1 3 3 3 3 3 3 5
 *     1 1 1 1 1 1 3 3
 *       1 1 1 1 1 1 3
 *         1 1 1 1 1 1
 *           1 1 1 1 1
 *             1 1 1 1
 *               1 1 1
 *                 1 1  从下往上横向遍历
 *                   1  |
 * ------------------------------------------*/
int longestHuiwenXulie(string s)
{
    int n = s.length();
    vector<vector<int>>dp(n,vector<int>(n,0));//base case 二维数组创建 全部填充0
    // 对角线全部填充 表示单个字符的时候
    for(size_t i = 0;i<n;i++)
        dp[i][i] = 1;

    // 从下往上遍历
    for(int i = n-1;i>=0;i++)
    {
        // 从左到右遍历
        for(int t = i+1;t<n;t++)
        {
            if(s[i] == s[t])// s[i+1,t-1] 这一子序列中两端如果出现相同字符 那么就符合回文结构 长度+2
                dp[i][t] = dp[i+1][t-1]+2;
            else
                dp[i][t] = max(dp[i][t-1],dp[i+1][t]);
        }
    }

    return dp[0][n-1];
}

int main()
{
    string s = "ababfgjkab";

    longestHuiwenXulie(s);
    return 0;
}