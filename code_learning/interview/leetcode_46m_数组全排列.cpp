#include <iostream>
#include <vector>

using namespace std;

/* -------------------------------------------
 * 类似于DFS深度 前序遍历
 * 添加了一个辅助状态判断数组 用来判断是否用过
 * 递归过程同leetcode17
 * 注意：及时pop出去 及时更新状态位 即可
 * 遍历要灵活使用 不论是根据索引还是直接取值 这里要同步更新状态数组backup所以用索引方便
 * ------------------------------------------*/
// 1 - 长度与总长度相同 代表该元素是否使用过 可以用map的 可能当时还不会
vector<int> backup;

void permuteHelper(vector<int>&nums,vector<vector<int>>&result,vector<int>temp)
{
    // 2、再看结束：递归结束标志
    if(temp.size() == nums.size())
    {
        result.push_back(temp);
        return;
    }

    // 3、中间部分
    for(int i = 0;i<nums.size();i++)
    {
        if(0 == backup[i])
        {
            temp.push_back(nums[i]);
            backup[i] = 1;
            permuteHelper(nums,result,temp);
            temp.pop_back();
            backup[i] = 0;
        }
    }
    temp.pop_back();
}

void permute(vector<int> &nums)
{
    vector<vector<int>> result;
    vector<int>temp;
    sort(nums.begin(),nums.end());

    // 1、先看开始：首位取1，2，3
    // 最外层递归 选择首端元素
    for(int i = 0;i<nums.size();i++)
    {
        temp.push_back(nums[i]);
        backup[i] = 1;
        permuteHelper(nums,result,temp);
        backup[i] = 0;
        temp.pop_back();
    }
    return ;
}


// 2 - dfs 因为本身不存在重复数字 所以可以直接递归
vector<vector<int>> permutedfs(vector<int>& nums) {
    vector<vector<int>>result;
    vector<int>temp;
    DFS(nums,temp,result);

    return result;
}
void DFS(vector<int>&nums,vector<int>temp,vector<vector<int>>&result)
{
    if(temp.size() == nums.size())
    {
        result.push_back(temp);
        return;
    }

    for(int i = 0;i<nums.size();i++)
    {
        if(find(temp.begin(),temp.end(),nums[i])==temp.end())
        {
            temp.push_back(nums[i]);
            DFS(nums,temp,result);
            temp.pop_back();
        }
    }
    return;
}

int main()
{
    // 首先准备好nums target
    vector<int> nums {1,2,3};
    for(auto i : nums)
        backup.push_back(0);
    permute(nums);

    return 0;
}