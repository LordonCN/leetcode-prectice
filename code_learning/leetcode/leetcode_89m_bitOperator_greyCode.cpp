#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

/* -------------------------------------------
 * 位操作
 * 1<<2 == pow(2,2)
 * ^ 异或运算 相同为0 不同为1 功能：格雷码
 * & 与运算 功能：清零、取指定位
 * | 或运算 功能：指定位置1
 * ------------------------------------------*/

void dfs(int n, int& x,vector<int>&ans) {
    ans.push_back(x);
    
    for (int i = 1; i <= n; i++)
    {
        x ^= (1 << i - 1);
        dfs(i - 1, x,ans);
    }
}

int main()
{
    vector<int>ans;
    // dfs解法
    // int x = 0;
    // dfs(5, x, ans);

    // i^(i/2)
    int n = 5;
    int sum = pow(2,n);
    for(int i = 0;i<sum;i++)
    {
        ans.push_back(i^(i/2));// 太巧妙了
    }

    return 0;
}
