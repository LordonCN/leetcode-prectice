#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

/* -------------------------------------------
 * 返回两个数可以用pair
 * pair与map本质相同 可以把map作为容器 insert pair类型配对数据
 * vector 也可以作为pair容器
 *
 * * 注意两者作为容器进行遍历方法不一样
 * * vector[number].first
 * * vector[number].second
 * * map[first] = second
 * ------------------------------------------*/
pair<string,int> pairTest(vector<pair<int,int>>&nums)
{
    // make pair 将两个数据组合成结构体返回
    int makepair = 2;
    auto pairout1 = make_pair("output is",makepair);

    // vector可容纳pair 不过必须定义pair类型存储内容
    // 所以不建议存vector
    nums.push_back(make_pair(1,2));
    cout<<nums[0].first;
    cout<<nums[0].second;

    // hashmap 可存储pair 直接pair后insert
    // 特殊点：map也是存储结构体 与pair本质相同 所以两者兼容性高
    unordered_map<string,int> hashstringmap;
    hashstringmap.insert(pairout1);
    hashstringmap.insert(make_pair("test",1));
    hashstringmap.insert(pair<string,int>("test",1));
    hashstringmap.insert({"hello",6});
    for(auto i : hashstringmap)
        cout<<i.second<<endl;


    return pairout1;
}

int main()
{
    // 首先准备好nums target
    vector<pair<int,int>> nums;

    pair<string,int> result;
    result = pairTest(nums);

    return 0;
}