#include <iostream>
#include <unordered_map>
#include <vector>
#include <numeric>

using namespace std;

/*
 * 转化为找元素和为sum的一半
 * ac 20 63
 */
int main()
{
    vector<int>nums{1,1,1,1,1};
    int target = 3;
    int sum = accumulate(nums.begin(),nums.end(),0);
    int end = (sum+target)/2;
    vector<int>dp(end+1,0);

    dp[0] = 1;

    for(auto num:nums)
    {
        for(int j = end;j>=num;j--)
        {
            dp[j] = dp[j]+dp[j-num];
        }
    }
    return 0;
}
