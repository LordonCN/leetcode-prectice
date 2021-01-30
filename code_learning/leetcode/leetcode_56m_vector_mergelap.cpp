#include <iostream>
#include <vector>
#include <algorithm>

/* -------------------------------------------
 * 相似：T435
 * 思路：按照首位排序后比较左右区间，右左区间大小 满足条件即保存新区间
 * 更新：补充lambda表达式 重写sortCmp
 * ------------------------------------------*/
using namespace std;

bool sortCmp(const vector<int>&a,const vector<int>&b)
{
    return a[0] < b[0]; // 升序 < 降序
}

void twoParts(vector<vector<int>> &nums) // 这里直接nums  *nums需要用->
{
    vector<vector<int>> result;
    if(nums.size()<2) return ;

    sort(nums.begin(),nums.end(),sortCmp);
    // sort(nums.begin(),nums.end(),[](const vector<int>&a,const vector<int>&b){return a[0]<b[0];});

    int lowNumber = nums[0][0];
    int highNumber = nums[0][1];

    // 只判断到倒数第二个
    for(int i = 0;i < nums.size()-1;i++)
    {
        // 按照首位排序后 左侧的最大值如果大于右侧最小值那么说明需要进行合并 至于合并为啥要根据连个区间的最大值决定
        if(highNumber > nums[i+1][0])
        {
            highNumber = max(highNumber,nums[i+1][1]);// 更新最大值
        }
        else
        {
            result.push_back({lowNumber,highNumber});
            // 更新最小值
            lowNumber = nums[i+1][0];
            highNumber = nums[i+1][1];
        }

        // 最后一个被替换了的时候保存一下
        if(i == nums.size()-2)
            result.push_back({lowNumber,highNumber});
    }

    // 添加一下最后一个
    if(result[result.size()-1][1] >= nums[nums.size()-1][1])
        return ;
    else
        result.push_back(nums[nums.size()-1]);
    return;

}


int main()
{
    // 首先准备好nums target
    vector<vector<int>> nums{{1,6},{2,3},{2,5}};
    nums.push_back({5,6});
    nums.push_back({8,9});

    vector<vector<int>>result;
    twoParts(nums);

    return 0;
}