#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

/* -------------------------------------------
 * vector题目 超时 动态规划类似于爬台阶
 * 递归就先做到这里吧
 * 相似：39题 40 17 22 216
 * ------------------------------------------*/
void Helper(vector<int>aim,
            vector<vector<int>>&result,
            vector<int>&temp,
            int target)
{
    if(accumulate(temp.begin(),temp.end(),0) == target)
        result.push_back(temp);

    if(accumulate(temp.begin(),temp.end(),0) > target)return;

    for(int i = 0;i<aim.size();i++)
    {
        temp.push_back(aim[i]);
        Helper(aim,result,temp,target);
        temp.pop_back();
    }
    return ;
}

int combinationSum4(vector<int>& aim, int target) {
    vector<vector<int>>result;
    vector<int>temp;

    for(int i = 0;i<aim.size();i++)
    {
        temp.push_back(aim[i]);// 首字母
        Helper(aim,result,temp,target);
        temp.pop_back();
    }
    return result.size();
}

// 需要考虑顺序问题 将数组放里面遍历
// ac 组合+排序 动态规划过程中需要
// TODO:这个最大值阈值设置有点奇怪？？？
int combinationSum4(vector<int>& nums, int target) {
    vector<int>dp(target+1,0);
    dp[0] = 1;
    for(int i = 1;i<=target;i++)
    {
        for(int j = 0;j<nums.size();j++)
            if(i>=nums[j] && dp[i] < INT_MAX - dp[i - nums[j]])
                dp[i] = dp[i] + dp[i-nums[j]];
    }
    return dp[target];
}