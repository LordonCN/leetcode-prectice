#include <iostream>
#include <string>

using namespace std;

/* -------------------------------------------
 * hash 细节补充
 * 重点：
 * ------------------------------------------*/
int countHelper(const string &s,int i,int j)
{
    int sum = 0;
    for(int epoch = i;epoch<=j;epoch++)
    {
        if(s[epoch] == '1') sum ++;
    }
    return sum;
}

int countSubstrings(const string &s)
{
    int sum = 0;
    for(int i = 0;i<s.length();i++)
    {
        for(int j = i+1;j<s.length();j ++)
        {
            if((j-i+1)%2 == 0 && (j-i+1)!=s.length()) // 偶数的时候进行判断 且保证是子串
            {
                int onenumber = countHelper(s,i,j);
                if(onenumber == (j-i+1)/2) sum ++;
            }
        }
    }

    return sum;
}

int main()
{
    // 首先准备好nums target
    string s = "00110011";

    countSubstrings(s);

    return 0;
}