#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

/* -------------------------------------------
 * 注意: ac 100 67%  动态规划 复杂度为n
 * 首先根据统计规律进行情况分类 找递推公式:`dp[i] = dp[i-1] + dp[i-2]`  `dp[i] = dp[i-1] + 1` `dp[i] = dp[i-1]`
 * 根据提交过程中的其他特殊情况进行总结归纳 特别是0的时候
 * ------------------------------------------*/
bool combinOK(char a,char b)
{
    int l = a-48;
    int r = b-48;
    int result = r*10+l;

    return 'A'<(64+result)&&(64+result)<='Z';
}

int decode(string s)
{
    vector<int>dp (s.size(),0);
    dp[0] = 1;

    for(int i = 1;i<s.size();i++)
    {
        if(s[i] == '0')
        {
            if(i ==1 && combinOK(s[i],s[i-1]))// 10
                dp[i] = 1;
            else if(combinOK(s[i],s[i-1]) && i>=2)// 110
                dp[i] = dp[i-1] = dp[i-2];
            else
                return 0;
        }
        else if(combinOK(s[i],s[i-1]) && i>=2 && s[i-1]!='0')//绝大多数情况
            dp[i] = dp[i-1] + dp[i-2];
        else if(combinOK(s[i],s[i-1])&& s[i-1]!='0')//前两个 12 11这种
            dp[i] = dp[i-1] + 1;
        else//207  中间存在0的情况
            dp[i] = dp[i-1];
    }

    return s[0]=='0'? 0 : dp[s.size()-1];
}

int main()
{
    string s = "207";
    decode(s);
    return 0;
}