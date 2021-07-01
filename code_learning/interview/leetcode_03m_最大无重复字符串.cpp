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
 * 干嘛要删除呢？？
 * 3-queue+map 也挺简单 楼下优化
 * 4-双指针+map 减少了queue的pop以及push操作 高了一点
 * 注意：ac 60.4%  52.0%
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
 * 思路3
 * ------------------------------------------*/
int lengthOfLongestSubstring(string s) {
    queue<int>que;
    map<char,int>hash;
    if(s == "")return 0;

    que.push(s[0]);
    hash[s[0]] = 1;
    int maxlength = 1;
    for(int i = 1;i<s.length();i++)
    {
        // 判断一下当前字符是否出现过？
        if(hash[s[i]])
        {
            // hash[s[i]] = 0;// 因为前面剔除了后面还要加进去 所以这里不用置位
            while(que.front() != s[i])
            {
                hash[que.front()] = 0;
                que.pop();
            }
            que.pop();
            que.push(s[i]);
        }
        else
        {
            que.push(s[i]);
            hash[s[i]] = 1;
            maxlength = maxlength>que.size()?maxlength:que.size();
        }
    }
    return maxlength;
}

/* -------------------------------------------
 * 思路4
 * ------------------------------------------*/
// 1、使用queue进行存储空间消耗较大 push pop操作比较费时
// 2、使用双指针进行优化
int lengthOfLongestSubstring(string s) {
    map<char,int>hash;
    if(s == "")return 0;

    // 初始化状态 添加第一个字符
    hash[s[0]] = 1;
    int maxlength = 1;
    int start(0),end(1);

    for(int end = 1;end<s.length();end++)
    {
        // 判断一下当前字符是否出现过？
        if(hash[s[end]])
        {
            // hash[s[i]] = 0;// 因为前面剔除了后面还要加进去 所以这里不用置位
            while(s[start] != s[end])
            {
                hash[s[start]] = 0;
                start+=1;
            }
            start += 1;// untile s[start] == s[end]
        }
        else
        {
            hash[s[end]] = 1;
        }
        maxlength = max(maxlength,end-start+1);
    }
    return maxlength;
}

int main()
{
    string s = "kubdypzxdivrqa";

    lengthOfLongestSubstring(s);


    return 0;
}




