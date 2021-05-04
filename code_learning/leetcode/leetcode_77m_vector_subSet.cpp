#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

/* -------------------------------------------
 * 思路：ac 5 5
 * 模仿leetcode 46 48 78递归完成
 * 使用DFS 同时涉及迭代器查找
 * ------------------------------------------*/
void DFS(vector<vector<int>>&result,vector<int>temp,
            const vector<int>&nums,int k,int p)
{
    if(temp.size() == k)
    {
        result.push_back(temp);
        return;
    }
    for(int i = p;i<nums.size();i++)
    {
        vector<int>::iterator ite;
        ite = find(temp.begin(),temp.end(),nums[i]);
        // 如果当前值在其中不存在
        if(ite == temp.end())
        {
            temp.push_back(nums[i]);
            DFS(result,temp,nums,k,i);
            temp.pop_back();
        }
        

    }
    return;
}
int main()
{
    // 使用递归
    // subSet(nums);
    int n = 4;

    vector<int>nums(n,0);
    for(int i = 1;i<=n;i++)
        nums[i-1] = i;
    vector<vector<int>>result;
    vector<int>temp;
    DFS(result,temp,nums,k,0);
    // return result;
    return 0;
}