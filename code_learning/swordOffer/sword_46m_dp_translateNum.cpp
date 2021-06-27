#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int translateNum(int num) {
    string temp;
    temp = to_string(num);
    if(temp == "")return 0;
    vector<int>dp(temp.length(),0);
    dp[0] = 1;//第一个肯定有一个

    for(int i = 1;i<temp.length();i++)// 从第二个开始遍历
    {   // 当前项与前一项是否能够组成两位数的情况
        if('1'== temp[i-1] || temp[i-1] =='2' && temp[i] <='5')// 10-19 20-25
        {
            if(i>1)// 数量超过3的时候 如果自己个体 那么就是dp[i-1] 如果跟前面能拼接 那么就是dp[i-2]
                dp[i] = dp[i-1] + dp[i-2];
            else // 前两项的时候 只是多了一种情况
                dp[i] = dp[i-1] + 1;
        }

        else// 当前项无更多组合方式
            dp[i] = dp[i-1];
    }
    int result = dp[temp.length()-1];
    return result;
}
int main()
{

    translateNum(122516);

    return 0;
}