#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

/* -------------------------------------------
 * 有关字符串的递归操作
 *
 * ------------------------------------------*/

using namespace std;

int maxlength = 0;
void maxString(string s,int deepth,vector<char> &temp)
{
    //3
    if(deepth == s.length()) return ;

    //2
    if(s[deepth] == temp[temp.size()-1])
    {
        temp.push_back(s[deepth]);
        maxlength ++;
    }
    else
    {
        temp.erase(temp.begin(),temp.end());
        maxlength = 1;
        temp.push_back(s[deepth]);
    }
    maxString(s,deepth+1,temp);

    return ;
}


int main()
{
    string s = "ABAAABBBA";
    vector<char>temp;
    // 1、递归 遍历所有
    for(char &i:s)
    {
        i = i == 'A'? 'B':'A'; // 交换
        temp.push_back(s[0]);
        maxlength = 1;
        maxString(s,1,temp);
    }


    return 0;
}