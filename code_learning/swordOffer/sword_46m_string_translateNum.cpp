#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*************************************************************************
 * offer46 ac 100 37
 * 思路:首先把情况列出来 同leetcode198 打家劫舍
 * 如果第i位与前面一位的组合数字在 10~25之间
 *======================================================================*/
int translateNumber(int num)
{
    string temp;
    temp = to_string(num);
    if(temp == "")return 0;
    vector<int>dp(temp.length(),0);
    dp[0] = 1;//第一个肯定有一个
    for(int i = 1;i<temp.length();i++)
    {
        if('1'== temp[i-1] || temp[i-1] =='2' && temp[i] <='5')// 10-19 20-25
            if(i>1)
                dp[i] = dp[i - 1] + dp[i - 2];
            else
                dp[i] = dp[i - 1] + 1;

        else
            dp[i] = dp[i-1];
    }


    int result = dp[temp.length()-1];

    return result;
}

int main()
{
    int num = 123;

    translateNumber(num);

    return 0;
}