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
 *  这里求的是最小平方数的个数之和，所以初始化为最大值，用min来更新数组
 * ------------------------------------------*/
int numSquares(int target) {
    vector<int> dp(target+1, INT_MAX);;
    dp[0]=0;
    for(int num = 1; num <= n/2; num++){
        for(int i = 0; i <= target; i++){
            if(i >= num * num)
                dp[i] = min(dp[i], dp[i - num * num] + 1);
        }
    }
    return dp[target];
}

int main()
{
   numSquares(5):
   return 0;
}
