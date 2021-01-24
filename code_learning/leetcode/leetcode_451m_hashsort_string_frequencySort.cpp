#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;
/* -------------------------------------------
 * cpp哈希表的创建方法unordered_map<int,int> hashMap;
 * hash  遍历方法for (auto n : hashMap)
 * vector 一行创建vector<int> nums {4,4,0,0,4,1,6,9,8,13};
 * vector 遍历方法for(auto number : nums)
 * ------------------------------------------*/
bool sortVector2d(const vector<int>a,const vector<int>b)
{
    return a[1]>b[1]; // 逆序
}


void frequencySort(string S)
{
    // 创建hashmap
    unordered_map<char,int> hashmap;

    // 对string出现元素做统计
    for(auto C : S) hashmap[C] += 1;

    // hash 提取到vector
    vector<vector<int>>res;
    for(auto [c,v] : hashmap) res.push_back({c,v});

    // 根据出现频率进行排序
    std::sort(res.begin(),res.end(),sortVector2d);

    // string 拼接
    // 通过对二维数组遍历后 对数值自减来添加到字符串中
    string output = "";
    for(auto a : res)
    {
        while(a[1]-->0)
        {
           output += a[0] ;
        }
    }

    // return output 即可

    return ;
}

int main()
{
    string s = "treere";
    frequencySort(s);

    return 0;
}