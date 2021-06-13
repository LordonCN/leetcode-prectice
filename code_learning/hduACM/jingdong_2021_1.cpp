#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>


using namespace std;

int main()
{
//    int n,m,C;
//    cin>>n>>m>>C;
//    vector<int>store;
//
//    // 读进来奶茶
//    for(int i = 0;i<n;i++)
//    {
//        int temp;
//        cin>>temp;
//        store.push_back(temp);
//    }
//    int result = 0;
//    stack<int> sk;
//    if(store.size()<m)// 奶茶比人少 一人喝一杯即可
//    {
//        for(int i = 0;i<3;i++)
//            result = max(result,store[i]/C);
//        cout<<result;//TODO:这里要向上取整
//    }
//    else
//        {
//            // 奶茶比人多 需要整合区间
//            while(store.size()>3)
//            {
//
//
//            }
//        }

    int n ,m ;
    cin>>n>>m;
    vector<vector<int>>dp(n,vector<int>(n,0));
    for(int i = 0;i<n;i++)
    {
        for(int j = 0;j<n;j++)
        {
            int temp;
            cin>>temp;
            dp[i][j] = temp;
        }
    }
    int j = 0;
    int i = 1;

    for(int k = 3;k<m+1;k++)
    {
        int today = dp[i][j];
        if(k==m) cout<<today;
        j = i;
        i = today -1;
    }
    if(m <= 2) cout<<m;

    return 0;
}