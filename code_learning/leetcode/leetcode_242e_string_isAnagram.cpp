#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

/* -------------------------------------------
 * hash 细节补充
 * 重点：
 * hash[A] = key
 * 类似：
 * 01 205
 * ------------------------------------------*/
bool isAnagram(const string s,const string t)
{
    unordered_map<char,int>hash;
    for(int i = 0;i<s.length();i++)
    {
        // 如果索引内容部位hash.end() 那么自动创建并且second默认是0
        hash[s[i]] ++;
        hash[t[i]] --;
    }
    for(auto i : hash)
    {
        if(i.second)return false;
    }

    return true;
}

int main()
{
    // 首先准备好nums target
    string s = "anagram";
    string t = "nagaram";

    isAnagram(s,t);

    return 0;
}