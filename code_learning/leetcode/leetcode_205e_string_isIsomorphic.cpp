#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

/* -------------------------------------------
 * hash 细节补充
 * 重点：
 * hash.find(A) != hash.end() 如果表中能够找到A这个键值则执行
 * hash[A] = key
 * 类似：
 * 01
 * ------------------------------------------*/
bool isIsomorphic(string &s,const string t)
{
    unordered_map<char,char>hash;
    for(int i = 0;i<s.length();i++)
    {
        if(hash.find(s[i]) == hash.end())
        {
            hash[s[i]] = t[i];
            s[i] = t[i];
        }
        else
            s[i] = hash[s[i]];
    }
    if(s == t)
        return true;
    else
        return false;
}

int main()
{
    // 首先准备好nums target
    string s = "paper";
    string t = "title";

    isIsomorphic(s,t);

    return 0;
}