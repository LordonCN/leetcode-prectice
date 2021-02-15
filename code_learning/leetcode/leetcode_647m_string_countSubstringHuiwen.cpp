#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

/* -------------------------------------------
 * 重点：
 * reverse string翻转
 * 延伸：
 * reverse vector翻转 本质相同
 * ------------------------------------------*/
int coutHuiwen(const string s)
{
    int sum = s.length();
    string temp = s;
    for(int i = 0;i<s.length();i++)
    {
        for(int ii = i+1;ii<s.length();ii++)
        {
            reverse(temp.begin()+i,temp.begin()+ii+1);
            if(s == temp) sum++;
            reverse(temp.begin()+i,temp.begin()+ii+1);
        }

    }
    return sum;
}

int main()
{
    // 首先准备好nums target
    string s = "baabaab";

    coutHuiwen(s);

    return 0;
}