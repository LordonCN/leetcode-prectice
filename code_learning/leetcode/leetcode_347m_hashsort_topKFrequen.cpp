#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>
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

/* -------------------------------------------
 * 遍历hash
 * ------------------------------------------*/
void coutAllNumbersInHash(unordered_map<int,int>hashMap)
{
    for(const auto&each : hashMap)
        cout<<"hash value is:"<<each.first<<" and times is "<<each.second<<endl;
}

void topKNumber(std::vector<int> &nums,int K)
{
    if(nums.size()<2)
        return;

    // 创建hashmap
    unordered_map<int,int> hashMap ;
    // 形式2的hash集合

    // hash 统计数字出现频率 索引为数字数值
    // vector 遍历方法
    for(auto number : nums) hashMap[number] += 1;

    // 因为要对hash中存储数据的出现频率进行排序
    // hash内容转化为二维保存 hash遍历方法
    vector<vector<int>> res;
    for (auto n : hashMap) res.push_back({n.first,n.second});

    // hash表遍历方法2
    coutAllNumbersInHash(hashMap);

    // 2dvector 对出现频率进行排序
    sort(res.begin(),res.end(),sortVector2d);

    // 最后针对347题从高到低输出出现频率降低的数字
    // 将二维中数字提取出来
    vector<int> output;
    for(int i = 0;i<K;i++)
        output.push_back(res[i][0]);
}

int main()
{
    // 首先准备好nums target
    std::vector<int> nums {4,4,0,0,4,1,6,9,8,13};

    int k = 2;
    topKNumber(nums,k);

    return 0;
}