#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <unordered_map>

using namespace std;

/* -------------------------------------------
 * 字符串排序 sort默认方法即可 因为倒序、二维、字符串拼接搞得默认sort都写函数了..
 * 同型异构字符串先考虑本身排序 并保存至map中 方便查询
 * map 中可以对具有相同特征的一类数据进行保存
 * ------------------------------------------*/
void groupAnagrams(vector<string>& str)
{
    // 保存temp结果
    vector<vector<string>>result;
    // 保存单次查询结果
    vector<string>temp;

    // 涉及到char类型数据 字符排序
    unordered_map<string,vector<string>> hash;
        // 拷贝的问题
        // 保存到map中之后 first为原来值 second为相同值
    for(auto i : str)
    {
        string temp = i;
        sort(i.begin(),i.end()) ;
        hash[i].push_back(temp);
    }
    for(auto j : hash)
        result.push_back(j.second);

    return ;
}

int main()
{
    vector<string> str{"eat", "tea", "tan", "ate", "nat", "bat"};

    groupAnagrams(str);

    return 0;
}




