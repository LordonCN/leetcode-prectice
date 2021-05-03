#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

/* -------------------------------------------
 * 思路：ac 6 13
 * 模仿leetcode 46 48 递归完成
 * 使用DFS+集合遍历所有情况 * 同时涉及迭代器查找
 * ------------------------------------------*/

 void DFS(set<vector<int>>&result,
        const vector<int>& nums,
        vector<int>temp,
        int n,
        vector<int>&sign){  
    if(temp.size() == nums.size())return;
    for(int i = n;i<nums.size();i++)
    {
        if(sign[i] == 0){
            sign[i] = 1;
            temp.push_back(nums[i]);
            // sort(temp.begin(),temp.end());
            result.insert(temp);
            DFS(result,nums,temp,i,sign);
            temp.pop_back();
            sign[i] = 0;
        }
    }
    return;
}

int main()
{
    vector<int> nums{1,2,3,0};
    set<vector<int>>result;
    vector<int>temp;
    result.insert(temp);
    vector<int>sign(nums.size(),0);
    DFS(result,nums,temp,0,sign);
    // 去除重复
    set<vector<int>>result2;
    for(auto i:result)
    {
        sort(i.begin(),i.end());
        result2.insert(i);
    }
    vector<vector<int>>out;
    for(auto i:result2)
        out.push_back(i);
    return 0;
}