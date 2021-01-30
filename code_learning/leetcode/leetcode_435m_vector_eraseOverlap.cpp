#include <iostream>
#include <vector>
#include <algorithm>

/* -------------------------------------------
 * 要求让区间相互不重叠
 * 相似：T56
 * 思路：按照首位排序后比较左右区间，右左区间大小 满足条件即保存新区间
 * 更新：补充lambda表达式 重写sortCmp
 * ------------------------------------------*/
using namespace std;

bool sortCmp(const vector<int>&a,const vector<int>&b)
{
    return a[1] < b[1]; // 升序 < 降序
}

void twoParts(vector<vector<int>> &nums) // 这里直接nums  *nums需要用->
{
    if(nums.size()<2) return ;

    sort(nums.begin(),nums.end(),sortCmp);
    // sort(nums.begin(),nums.end(),[](const vector<int>&a,const vector<int>&b){return a[0]<b[0];});

    int highNumber = nums[0][1];
    int output = 0;

    // 此题目只要判断最后一个是否跟倒数第二个是否有冲突 没有冲突直接过 有冲突再循环就统计了
    for(int i = 1;i < nums.size()-1;i++)
    {
        // 按照首位排序后 左侧的最大值如果大于右侧最小值那么说明需要跳过
        if(highNumber > nums[i][0])
        {
            // 跳过
            output ++;
        }
        else
        {
            highNumber = nums[i][1];
        }
    }

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