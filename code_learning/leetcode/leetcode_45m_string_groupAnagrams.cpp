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
 * 思路：
 * 1、根据题目描述肯定需要将结果先添加到vector中 并且分好类 之后添加到vector<vector>中
 * 2、考虑将所有元素分类后同一类型元素保存到一个vector中
 * 3、同种类型均有一个共同点 组成元素相同 所以可以使用单词排序的想法将他们append到一个vector
 * 4、为了索引方便 改用map存储 更加直观
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




