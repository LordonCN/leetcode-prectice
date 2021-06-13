
#include <iostream>
#include <string>
#include <sstring>

using namespace std;

/* -------------------------------------------
 * 思路：
 * 1、之前使用栈+switch进行判断过 代码冗杂且易混
 * 2  使用geline可以直接对‘/’进行划分 得到了'' '.' '..' !'..' 四种情况
 * ------------------------------------------*/
string minPath(string path)
{
    vector<string> result;
    stringstream is(path); // 放入到string流中
    string res = "",tep = "";
    while(getline(is,tep,'/'))// 对string 按照 '/' 进行划分
    {
        if(tep == "" || tep == "..")
            continue;
        else if(tep == ".." && !result.empty())
            result.pop_back();
        else if(tep == "..") // 针对于/..的情况
            result.push_back(tep);
    }
    for(auto str:result)
        res +=  "/" + str;
    if(res.empty())
        return "/";


    return res;
}

int main()
{
    string path = "/../sdf/./..//a";
    simplifyPath(path);
    return 0;
}






