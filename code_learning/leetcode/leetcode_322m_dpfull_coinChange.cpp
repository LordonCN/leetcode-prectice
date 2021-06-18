#include <iostream>
#include "listNode.h"
#include <string>
#include <vector>
using namespace std;

/* -------------------------------------------
 * 完全背包问题 不考虑coins顺序问题 所以一个能无限用
 * 外层target
 * 内层遍历所有num
 * 注意：
 *  这里求的是最小组合数，所以初始化为最大值，用min来更新数组
 * ------------------------------------------*/
int coinChange(const vector<int>& coins, int amount) {
    vector<int> dp(amount+1, INT_MAX);
    dp[0] = 0;
    for(auto coin: coins)
    {
        for(int i = 1; i <= amount; i++)
        {
            if(coin <= i)
                dp[i] = min(dp[i], dp[i-coin] + 1);
        }
    }
    return dp[amount] == INT_MAX ? -1 : dp[amount];
}

int main()
{
    vector<int>coins{3,4,5};
    int amount = 12;

   return 0;
}
