#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <memory>
#include <math.h>

using namespace std;

int main() {


    /**input**/
    int N= 0,M = 0;
    cin >> N >> M;
    vector<int>temp(N,0);
    for (int i = 0; i < N; i++)
    {
        cin >> temp[i] ;
    }
    int r = N/2;
    while(M--)// 洗牌M次
    {
        vector<int>result;

        for(int i = 0;i<r;i++)
        {
            result.push_back(*(temp.begin()+i+r));
            result.push_back(*(temp.begin()+i));
        }
        if(temp.size()<result.size())result.pop_back();
        temp = result;
    }
    for(int i = 0;i<N;i++)
    {
        cout<<temp[i]<<' ';
    }


    return 0;
}