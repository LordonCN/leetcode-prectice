#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// sort vector 二维数组排序
bool sortCmp(const vector<int>&a,const vector<int>&b)
{
    return a[0] < b[0]; // 升序 < 降序
}

vector<vector<int>> twoParts(vector<vector<int>> nums) // 这里直接nums  *nums需要用->
{
    if(nums.size()<2) return nums;
    sort(nums.begin(),nums.end(),sortCmp);
    int lowNumber = nums[0][0];
    int highNumber = nums[0][1];
    vector<vector<int>> result;

    for(int i = 0;i < nums.size()-1;i++)
    {
        // 更新最大值
        if(highNumber > nums[i+1][0]) // 左侧最大大于右侧最小
        {
            highNumber = max(highNumber,nums[i+1][1]);
        }
        else
        {
            result.push_back({lowNumber,highNumber});
            // 更新最小值
            lowNumber = nums[i+1][0];
            highNumber = nums[i+1][1];
        }
        // 若是已经到了倒数第二个 那么要及时更新了
        if(i == nums.size()-2)
        {
            result.push_back({lowNumber,highNumber});
            // 更新最小值
//            lowNumber = nums[i+1][0];
//            highNumber = nums[i+1][1];
        }

    }

    // 添加一下最后一个
    if(result[result.size()-1][1] >= nums[nums.size()-1][1])
        return result;
    else
        result.push_back(nums[nums.size()-1]);

}


int main()
{
    // 首先准备好nums target
    vector<vector<int>> nums{{1,6},{2,3},{2,5}};
    nums.push_back({1,6});
    nums.push_back({2,3});
    nums.push_back({2,5});
    nums.push_back({5,6});
    nums.push_back({8,9});

    vector<vector<int>>result;
    result = twoParts(nums);



    return 0;
}