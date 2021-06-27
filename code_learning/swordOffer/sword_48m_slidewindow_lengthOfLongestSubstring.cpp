#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

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
int main()
{

    string s = "ksljdfklks";
    lengthOfLongestSubstring(s);

    return 0;
}