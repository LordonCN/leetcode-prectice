#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

/* -------------------------------------------
 * 思路：
 * 1、根据题目描述 对于复杂度为n的题目来说 使用hash是很简单合适的方法 这里使用hash进行存储
 * 2、首先实现计算substring长度 再进行string裁剪操作 s.substr()
 * ------------------------------------------*/
int lengthHelp(int a,int b,int c)
{
    return max(max(a,b),c) - min(min(a,b),c) + 1;
}

int minlength(string s)
{
    int minlength = s.length();
    unordered_map<char,int>hash;
    for(int i = 0; i< s.length();i++)
    {
        if(s[i] == 'A'||s[i] == 'B'||s[i] == 'C')
            hash[s[i]] = i;
        if(hash.find('A')!=hash.end()&&hash.find('B')!=hash.end()&&hash.find('C')!=hash.end())
        {
            int length = lengthHelp(hash['A'],hash['B'],hash['C']);
            minlength = minlength<length? minlength:length;
        }
    }
    return minlength;
}

string minSubstring(string s)
{
    string subs;
    int minlength = s.length();
    unordered_map<char,int>hash;
    for(int i = 0; i< s.length();i++)
    {
        if(s[i] == 'A'||s[i] == 'B'||s[i] == 'C')
            hash[s[i]] = i;
        if(hash.find('A')!=hash.end()&&hash.find('B')!=hash.end()&&hash.find('C')!=hash.end())
        {
            int length = lengthHelp(hash['A'],hash['B'],hash['C']);
            if(minlength<length);
            else
            {
                minlength = length;
                subs = s.substr(min(min(hash['A'],hash['B']),hash['C']),minlength);
            }
        }
    }
    return subs;
}

int main()
{
    string s = "ADOBECODEBANC";

//    minlength(s);
    minSubstring(s);

    return 0;
}

