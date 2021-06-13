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
void subsetHelper(vector<vector<int>>&result,vector<int>&temp,const vector<int>&nums,int number)
{
    // 3、结束标志是number == nums.size()深度
    if(number == nums.size())
    {
        return;
    }

    // 2、中间部分处理
    for(int i = number+1;i<nums.size();i++)
    {
        temp.push_back(nums[i]);
        result.push_back(temp);
        subsetHelper(result,temp,nums,i);
        temp.pop_back();
    }
}

void subSet(vector<int>&nums)
{
    // 0、添加空集
    vector<vector<int>>result{{}};
    vector<int>temp;
    sort(nums.begin(),nums.end());

    // 1、第第一步 挨个遍历一遍
    for(int i = 0; i<nums.size(); i++)
    {
        temp.push_back(nums[i]);
        result.push_back(temp);
        subsetHelper(result,temp,nums,i);
        temp.pop_back();
    }
}

void DFS(set<vector<int>>&result,const vector<int>& nums,vector<int>temp,int n)
{
    if(temp.size() == nums.size())return;
    
    for(int i = n;i<nums.size();i++)
    {
        vector<int>::iterator ite;
        ite = find(temp.begin(),temp.end(),nums[i]);
        if(ite == temp.end())
        {
            temp.push_back(nums[i]);
            // sort(temp.begin(),temp.end());
            result.insert(temp);
            DFS(result,nums,temp,i);
            temp.pop_back();
        }
    }
    return;
}
int main()
{
    vector<int> nums{1,2,3,0};
    // 使用递归
    // subSet(nums);

    // 使用DFS+集合  
    set<vector<int>>result;
    vector<int>temp;
    result.insert(temp);
    DFS(result,nums,temp,0);
    vector<vector<int>>out;
    for(auto i:result)
        out.push_back(i);

    return 0;
}