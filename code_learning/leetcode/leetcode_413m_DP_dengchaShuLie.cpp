#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

/* -------------------------------------------
 * 注意： ac 100% 75%
 * nums是否是无序的 无序用hash
 * 等差数列 连续的等差 题目中要求的
 * ------------------------------------------*/
int DPshuLie(vector<int>&nums)
{
    vector<vector<int>>result;
    vector<int>temp;
    for(int i = 0;i<nums.size();i++)
    {
        if(temp.empty()) temp.push_back(nums[i]); //此循环第一个

        for(int i_ = i+1;i_<nums.size();i_++)
        {
            if(temp.size()<2)
            {
                temp.push_back(nums[i_]); //第二个添加
                continue;
            }
            // 从第三个开始 判断当前数字是否满足前面的等差
            if(temp.size()>=2 && ((nums[i_] - temp[temp.size()-1]) == (temp[temp.size()-1] - temp[temp.size()-2])))
            {
                temp.push_back(nums[i_]);
                if(temp.size()>=3) result.push_back(temp);
            }
            else break;
        }

        temp.erase(temp.begin(),temp.end());
    }
    return result.size();
}

/* -------------------------------------------
 * 注意：不能ac
 * 适用`无序`情况下 对所有可能性进行判断
 * 差为1 的时候
 * 使用hash进行存储 添加符合条件的结果到二维数组
 * ------------------------------------------*/
int shuLie(vector<int>& nums)
{
    vector<vector<int>>result;
    unordered_map<int,int>hash;
    vector<int>temp;
    int maxnum = 0;

    // hash首先存储
    for(int i = 0;i<nums.size();i++)
    {
        maxnum = maxnum>nums[i]?maxnum:nums[i];
        hash[nums[i]] = 1;
    }

    for(int num:nums) //取每一个用来逐次递增
    {
        if(temp.empty()) temp.push_back(num); //首个添加

        for(int i = num+1;i<=maxnum;i++)
        {
            if(hash.find(i) != hash.end())temp.push_back(i); // 符合等差数列
            else break;

            if(temp.size()>=3)result.push_back(temp);//添加到result
        }
        temp.erase(temp.begin(),temp.end());// 清除本数字等差数列 开始下一轮
    }
    return result.size();
}

int main()
{
    vector<int> nums{1,2,3,4};

    int result = DPshuLie(nums);

    return 0;
}