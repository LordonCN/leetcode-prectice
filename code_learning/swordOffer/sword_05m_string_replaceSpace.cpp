#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*************************************************************************
 * offer05   100 40
 * 将每一个空格替换为 %20 不论是开头还是结尾都要哦
 *======================================================================*/
string replaceSpace(string s)
{
    string str;
    for(auto i : s)
    {
        if(i == ' ')str += "%20";
        else
            str += i;
    }

    return str;
}

int main()
{
    string s = "we are happy ";

    replaceSpace(s);

    return 0;
}