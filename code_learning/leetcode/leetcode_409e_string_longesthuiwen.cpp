#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

/* -------------------------------------------
 * 注意: ac 9.6%  5.1%
 * 最长回文子序列与最长回文子字符串的区别
 * ------------------------------------------*/
int longestHuiwenXulie(string s)
{
    int sum = 0;
    unordered_map<char,int>hashmap;
    if(s.empty()) return 0;
    for(auto i : s)
    {
        hashmap[i] += 1;
        if(hashmap[i] == 2)// 为偶数就先统计一下
        {
            sum += 2;
            hashmap.erase(hashmap.find(i));
        }
    }
    return hashmap.empty()?sum:sum+1;
}

int main()
{
    string s = "abccccdd";

    longestHuiwenXulie(s);
    return 0;
}