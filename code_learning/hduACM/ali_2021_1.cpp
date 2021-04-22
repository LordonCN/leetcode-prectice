#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n ;//最远位置
        cin>>n;
        // 读取所有位置分值
        vector<int>reward(n,0);
        for(int i = 0;i<n;i++)
            cin>>reward[i];
        vector<vector<int>>dp(n,vector<int>(0));
    }

    return 0;
}