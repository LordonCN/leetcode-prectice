#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;


int main()
{
    int n= 0,k=0;
    // 一共n个罐 最多吃k个
    cin>>n>>k;
    vector<int>honey(n,0);
    for(int i = 0;i<n;i++)
        cin>>honey[i];

    // 特殊情况 如果n=2
    if(honey.size()<=2)
    {
        cout<<accumulate(honey.begin(),honey.end(),0)-k;
        return 0;
    }

    // 将相邻两个之和求出来放到新的矩阵里
    vector<int>maxNear;
    for(int i = 0;i<n-1;i++)
        maxNear.push_back(honey[i]+honey[i+1]);

    // 开始同时减小两个的值
    int maxpos = 0;
    int maxvalue = maxNear[0]+maxNear[1];
    // 吃几口
    for(int i = 0;i<k;i++)
    {
        for(int t = 0;t<maxNear.size()-1;t++)
        {
            if(maxNear[t]+maxNear[t+1]>maxvalue)
                maxpos = t;
        }

        maxNear[maxpos]--;
        maxNear[maxpos+1]--;
    }
    maxpos = 0;maxvalue = maxNear[0];
    for(int i = 0 ;i<maxNear.size();i++)
        if(maxNear[i]>maxvalue)maxpos = i;

    cout<<maxNear[maxpos];
    return 0;

}
