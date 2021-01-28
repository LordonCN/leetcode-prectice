#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <unordered_map>

using namespace std;

/* -------------------------------------------
 * 递归排列组合
 * 这个递归有点晕 绕了好久
 * 思路：
 * 1、首先参考leetcode12 创建一个表格用于查询
 * 2、排列组合与树形结构很显然 但是递归起来有点绕
 * 3、首先考虑第一个数字下的字符循环遍历 这里用 A_ 作为当前数字当前循环下取出的字符
 * 4、递归中
 * -------------------------------------------*/
void letterHelper(string digt,string &lettercombin,vector<string> &result,unordered_map<char,string> &dictionary)
{
    // 递归停止
    if(lettercombin.size()==digt.size()){
        result.push_back(lettercombin);
        // 此处清除该位叶子节点数值 退出当前递归为A_取下一个值做准备
        // 叶子节点表示每个数字都遍历到了 下面添加该数字表示字符的下一位
        lettercombin.pop_back();
        return;
    }

    // 取第一个2所指向的字符串{"a","b","c"} 此处能够保证递归返回后继续取第二个字母
    for(char A_ : dictionary[digt[lettercombin.size()]])
    {
        lettercombin += A_;
        letterHelper(digt,lettercombin,result,dictionary);
    }
    // 上层返回字符清除 飞叶子节点
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
    // 输入量多为了调试直观
    letterHelper(digt,lettercombin,result,dictionary);

    return ;
}

int main()
{
    string digt = "462";
    letterCombian(digt);
    return 0;
}




