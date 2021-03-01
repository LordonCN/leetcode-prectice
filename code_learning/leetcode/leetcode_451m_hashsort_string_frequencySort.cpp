#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;
/* -------------------------------------------
 * cpp哈希表的创建方法unordered_map<int,int> hashMap;
 * hash  遍历方法for (auto [c,v] : hashMap) vector.push_back({c,v})
 * vector 一行创建vector<int> nums {4,4,0,0,4,1,6,9,8,13};
 * vector 遍历方法for(auto number : nums)
 * 以及二刷出现的问题
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

string methord451(string s)
{
    if(s.size() == 0 )return "";
    unordered_map<char,int>hashmap;

    // 首先统计出现频率
    for(auto i : s)
        hashmap[i] += 1;

    // 这里出现了二维数组赋值的常见错误 把第一维度的vector当成了变量
    /*************************************************************************
    vector<vector<int>>store(hashmap.size(),vector<int>(1,0));
    for(auto i : s)
        store[i-'a'][0] = hashmap[i];

    sort(store.begin(),store.end(),[](vector<int>a,vector<int>b){return a[0]>b[0];});
    *======================================================================*/
    vector<vector<int>>store;
    for(auto [c,v] : hashmap)
        store.push_back({c,v});

    // 对二维数组第二个位置进行排序
    sort(store.begin(),store.end(),[](vector<int>a,vector<int>b){return a[1]>b[1];});

    string result;
    for(auto i : store)
        while(i[1]--)
            result += i[0] - 'a' + 'a';// 恢复成字符

    return result;
}

int main()
{
    string s = "treere";
    frequencySort(s);

    return 0;
}