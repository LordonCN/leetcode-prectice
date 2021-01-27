#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <unordered_map>

using namespace std;

/* -------------------------------------------
 * 这个递归有点晕 绕了好久
 * ------------------------------------------*/
/* -------------------------------------------
 * 递归排列组合
 * -------------------------------------------*/
void letterHelper(string digt,int time,string &lettercombin,vector<string> &result,unordered_map<char,string> &dictionary)
{
    // 递归停止
    if(lettercombin.size()==digt.size()){
        result.push_back(lettercombin);
        // 此处清除组合后的最后一位 叶子节点表示每个数字都遍历到了 下面添加该数字表示字符的下一位
        lettercombin.pop_back();
        return;
    }

    // 取第一个2所指向的字符串{"a","b","c"} 此处能够保证递归返回后继续取第二个字母
    for(char A_ : dictionary[digt[lettercombin.size()]])
    {
        lettercombin += A_;
        letterHelper(digt,time,lettercombin,result,dictionary);
    }
    //
    lettercombin.pop_back();

    return ;
}

void letterCombian(string digt)
{
    unordered_map<char,string> dictionary = {
            {'2',{"abc"}},
            {'3',{"def"}},
            {'4',{"ghi"}},
            {'5',{"jkl"}},
            {'6',{"mno"}},
            {'7',{"pqrs"}},
            {'8',{"tuv"}},
            {'9',{"wxyz"}}
    };
    vector<string> result;
    string lettercombin;
    letterHelper(digt,0,lettercombin,result,dictionary);

    return ;
}

int main()
{

    string digt = "462";

    letterCombian(digt);

    return 0;
}




