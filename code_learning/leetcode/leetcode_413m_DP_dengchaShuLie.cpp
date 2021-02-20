#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

/* -------------------------------------------
 * 注意：
 * nums是否是无序的 无序用hash
 * 等差数列 差为1 题目中要求的
 * ------------------------------------------*/

int shuLie(vector<int>& nums)
{
    vector<vector<int>>result;
    unordered_map<int,int>hash;
    vector<int>temp;
    int maxnum = 0;

    for(int i = 0;i<nums.size();i++)
    {
        maxnum = maxnum>nums[i]?maxnum:nums[i];
        hash[nums[i]] = 1;
    }

    for(int num:nums) //取每一个用来逐次递增
    {
        if(temp.empty()) temp.push_back(num);

        for(int i = num+1;i<=maxnum;i++)
        {
            if(hash.find(i) != hash.end())temp.push_back(i);
            else break;

            if(temp.size()>=3)result.push_back(temp);
        }
        temp.erase(temp.begin(),temp.end());// 清除本数字等差数列
    }
    return result.size();
}

int main()
{
    vector<int> nums{1,2,3,4};

    int result = shuLie(nums);

    return 0;
}