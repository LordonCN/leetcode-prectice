#include <iostream>
#include <unordered_map>
#include <set>
#include <string>
#include <vector>

using namespace std;

/* -------------------------------------------
 * 用map更适合我
 * 亮点：
 * 测试set效果
 * ------------------------------------------*/

void lengthOfLongestSubstring(string s)
{
    vector<char>stringStore;
    int maxLength = 0;
    unordered_map<char,int> hashmap;

    // 从第一个字符遍历
    for(int i = 0;i<s.length();i++)
    {
        hashmap.erase(hashmap.begin(),hashmap.end());
        hashmap[s[i]] ++;
        for(int k = i+1;k<s.length();k++)
        {
            hashmap[s[k]] ++;
            if(2 == hashmap[s[k]])
            {
                maxLength = maxLength>hashmap.size()? maxLength : hashmap.size();
                break;
            }
        }

    }
    return ;
}

void lengthOfLongestSubstring2(string s)
{
    vector<char>stringStore;
    int maxLength = 0;
    set<char>hashset;

    // 只测试插入操作
    for(auto it = s.begin();it<s.end();it++)
    {
        hashset.erase(hashset.begin(),hashset.end());
        hashset.insert(*it);
        hashset.find(*it);
    }
    return ;
}
int main()
{
    string s = "abcdefababab";

    lengthOfLongestSubstring2(s);


    return 0;
}




