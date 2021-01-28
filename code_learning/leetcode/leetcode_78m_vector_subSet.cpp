#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/* -------------------------------------------
 * 思路：
 * 模仿leetcode 46 48 递归完成
 * 真香
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

int main()
{
    vector<int> nums{1,2,3};
    subSet(nums);

    return 0;
}