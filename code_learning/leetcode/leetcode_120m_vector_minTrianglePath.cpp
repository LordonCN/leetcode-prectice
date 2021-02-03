#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

/* -------------------------------------------
 * stl大法好 存在问题：不是相邻节点
 * 动态规划 O(n)
 * ------------------------------------------*/
int minTrianglePath(vector<vector<int>> &nums)
{
    if(nums.size()<2)
    {
        sort(nums[0].begin(),nums[0].end());
        return nums[0][0];
    }
    int minnumber = 0;
    for(auto i : nums)
    {
        // 如果不加引用那就是浅拷贝
        sort(i.begin(),i.end());
        minnumber += i[0];
    }
    return minnumber;
}



int minPathDigui = INT16_MAX;
void helper(vector<vector<int>>&nums,int i,int j,vector<int>&temp)
{
    // 3、递归终止
    if((j+1)>nums.size())
    {
        minPathDigui = min(minPathDigui,accumulate(temp.begin(),temp.end(),0));
        return ;
    }
    if(i>=nums[j].size()) return ;
    if(i<0) return ;
    temp.push_back(nums[j][i]);

    // 2、中间部分
    helper(nums,i-1,j+1,temp);
    helper(nums,i,j+1,temp);
    helper(nums,i+1,j+1,temp);

    temp.pop_back();
    return ;
}

int minTrianglePathDy(vector<vector<int>> &nums)
{
    // 1.翻转一下 逐个遍历
    reverse(nums.begin(),nums.end());

    vector<int>temp;
    for(int i = 0;i< nums[0].size();i++)
    {
        // 第0行的第i个数值
        helper(nums,i,0,temp);
    }

    return minPathDigui;
}

int main()
{
    vector<vector<int>> nums {{2},{3,4},{6,5,7},{4,1,8,3}};

    int result;

    result = minTrianglePathDy(nums);
    // result = minTrianglePath(nums);

    return 0;
}