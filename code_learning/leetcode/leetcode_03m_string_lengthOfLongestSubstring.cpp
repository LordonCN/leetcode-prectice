#include <iostream>
#include <unordered_map>
#include <set>
#include <string>
#include <vector>
#include <deque>

using namespace std;

/* -------------------------------------------
 * 1-hashmap O(n2)
 * 2-deque+hashmap O(n) // 初步测试失败了 hashmap并不是按顺序添加进去的 但是可以单个擦除 我笑了
 * 注意：ac 44.4%  13.0%
 * ------------------------------------------*/
int lengthOfLongestSubstring(string s)
{
    unordered_map<char,int> hashmap;
    deque<int>dq;
    int maxLength = 0;
    // 从第一个字符遍历
    for(int i = 0;i<s.length();i++)
    {
        // 未找到该重复字符 添加
        if(hashmap.find(s[i])==hashmap.end())
        {
            dq.push_back(s[i]);
            hashmap[s[i]] ++;
            maxLength = maxLength>hashmap.size()? maxLength : hashmap.size();
        }
        else
        {
            // 更新dq 以及 hashmap中元素 这里时间耗费挺多 但是不到O(n)
            // 当前重复字符为s[i] hashmap中位置为hashmap.find(s[i])
            while(dq.front()!=s[i])
            {
                hashmap.erase(hashmap.find(dq.front())); //单个元素擦除
                dq.pop_front();
            }
            hashmap.erase(hashmap.find(dq.front()));
            dq.pop_front();
            // 把最前面的退出来放到后面
            dq.push_back(s[i]);
            hashmap[s[i]] ++;
        }
    }
    return maxLength;
}
/* -------------------------------------------
 * 测试hashset功能 非本题题解
 * ------------------------------------------*/
int lengthOfLongestSubstring2(string s)
{
    int maxLength = 0;
    set<char>hashset;

    // 只测试插入操作 使用指针
    for(auto it = s.begin();it<s.end();it++)
    {
        if(hashset.find(*it) != hashset.end())
        {
            hashset.insert(*it);
            maxLength = maxLength>hashset.size()?maxLength:hashset.size();
        }
        else
            hashset.erase(hashset.begin(),hashset.end());


    }
    return maxLength;
}

int main()
{
    string s = "kubdypzxdivrqa";

    lengthOfLongestSubstring(s);


    return 0;
}




