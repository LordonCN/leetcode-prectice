#include <iostream>
#include <vector>

using namespace std;

/* -------------------------------------------
 * 上下左右四个位置进行限制性锁紧 ac 34 51
 * 如果没有内部停止判断对话最后一行不好判断 
 * break是成功的关键
 * ------------------------------------------*/

vector<vector<int>> spiralOrder(int n) {
    vector<vector<int>>nums(n,vector<int>(n,0));
    int i = 1;
    int j = 0;
    int l = 0;
    int u = 0;
    int r = n-1;
    int d = n-1;
    while(true)
    {
        while(j<=r)nums[u][j++] = i++;
        if(l>r)break; u++;j=u;
        while(j<=d)nums[j++][r] = i++;
        if(u>d)break; r--;j=r;
        while(j>=l)nums[d][j--] = i++;
        if(r<l)break; d--;j=d;
        while(j>=u)nums[j--][l] = i++;
        if(d<u)break; l++;j=l;
    }
    return nums;

}

int main()
{
    int n = 10;
    spiralOrder(n);
    return 0;
}