#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

/* -------------------------------------------
 * hash 细节补充
 * 81/103
 * 用了hashmap存储 竟然比迭代器要好
 * ------------------------------------------*/
bool isAnagram(const string s,const string t)
{
    int sumLength = s.size();
    int slideWindow = t.size();
    if(slideWindow>sumLength)return false;

    for(int i = 0;i<sumLength-slideWindow;i++)
    {
        string cut = s.substr(i,i+slideWindow);
        unordered_map<char,int>hash;
        for(auto c : cut)
            hash[c] ++;
        for(auto c_ : t)
        {
            hash[c_]--;
            if(hash[c_] == -1)
                break;
        }
        return true;
    }
    return false;
}
/* -------------------------------------------
 * 74/103
 * 用了find 跟迭代器删除 差得多
 * ------------------------------------------*/
bool isAnagram1(const string s,const string t)
{
    int sumLength = s.size();
    int slideWindow = t.size();
    if(slideWindow>sumLength)return false;

    for(int i = 0;i<=sumLength-slideWindow;i++)
    {
        string cut = s.substr(i,slideWindow);
        for(char k : t)// 直接取t中字符
        {
            int pos = static_cast<int>(cut.find(k));
            if(pos == -1) goto next;
            string::iterator ite = cut.begin()+pos;
            ite = cut.erase(ite);
        }
        return true;
        next: nullptr;
    }
    return false;
}
/* -------------------------------------------
 * 103/103
 * 用了stl-sort 还是差一点啊
 * ------------------------------------------*/
bool isAnagram2(const string s,string t)
{
    int sumLength = s.size();
    int slideWindow = t.size();
    sort(t.begin(),t.end());
    if(slideWindow>sumLength)return false;

    for(int i = 0;i<=sumLength-slideWindow;i++)
    {
        string cut = s.substr(i,slideWindow);
        sort(cut.begin(), cut.end());
        if(cut == t)return true;
    }
    return false;
}
int main()
{
    // 首先准备好nums target
    string s = "anagram";
    string t = "aa";

    isAnagram(s,t);

    return 0;
}