#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

/* -------------------------------------------
 * 注意: ac 5% 5%
 * 通过对比 s.find()这一方法复杂度较高 与滑动窗口相比 远大于n复杂度
 * ------------------------------------------*/
int findSub(string s,string sub)
{
    // 边界条件判断
    if(s.length() == 0 && sub.length() == 0)return 0;
    if(s.length() != 0 && sub.length() == 0)return 0;

    int m = sub.length();
    bool result = false;

    while(s.find(sub[0]) != -1)
    {
        string temp = s.substr(s.find(sub[0]),m);
        if(temp == sub) return s.find(sub[0]);
        else
            s[s.find(sub[0])] = ' ';
    }
    return -1;
}

/* -------------------------------------------
 * 注意: ac 100% 62%
 * 滑动窗口复杂度为n
 * ------------------------------------------*/
int slideWindow(string s,string sub)
{
//    if(s.length() == 0 && sub.length() == 0)return 0;
//    if(s.length() != 0 && sub.length() == 0)return 0;
    if(s.length() == 0 && sub.length() != 0)return -1;// 这句话能提速

    int m = sub.length();
    int n = s.length();
    if(m>n) return -1;

    for(int i =0;i<s.length()-m+1;i++)
    {
        string temp = s.substr(i,m);
        if(temp == sub) return i;
    }

    return -1;
}

int return

int main()
{
    string s = "a";
    string sub = "a";

    findSub(s,sub);
    return 0;
}