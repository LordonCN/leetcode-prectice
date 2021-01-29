#include <iostream>
#include <vector>

using namespace std;

/* -------------------------------------------
 * 类似于DFS深度
 * 46题通过判断该数字是否用过来进行添加
 * 此题目通过将数字该位括号后添加了穿插这种中间操作
 * 递归过程同leetcode17
 * 注意：
 * 先添加左括号 回溯的时候清除左括号 添加右括号
 * 一开始想的时候就没有搞清楚这个该怎么递归 想成了() ()() ()()() 三种情况
 * ------------------------------------------*/

void generateHelper(vector<string>&result,string temp,int left,int right)
{
    // 2、再看结束：递归结束标志 左右括号均使用完毕
    if(0 == left&&0 == right)
    {
        result.push_back(temp);
        return;
    }

    // 3、中间部分
    // 关键一点就是先添加左括号 即最左侧一定是左括号
    if(left>0)
    {
        temp += '(';
        generateHelper(result,temp,left-1,right);
        // string数据不能用pop 用erase清除
        temp.erase(temp.size()-1,1);
    }
    if(right>left)
    {
        temp += ')';
        generateHelper(result,temp,left,right-1);
    }
}

void generate(int n)
{
    vector<string> result;
    string temp = "";

    // 1、先看开始：首位取1，2，3
    generateHelper(result,temp,n,n);

    return ;
}


int main()
{
    // 首先准备好nums target
    int nums = 3;
    generate(nums);

    return 0;
}