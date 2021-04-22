#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

/* -------------------------------------------
 * vector题目 ac 35 62
 * 相似：39题 40 17 22
 * ------------------------------------------*/
void Helper(int n,int k,
            vector<vector<int>>&result,
            vector<int>&temp,
            ){
    if(temp.size() == k && accumulate(temp.begin(),temp.end(),0) == n)
        result.push_back(temp);
    if(temp.size()==k)return;// 别再加4了
    if(accumulate(temp.begin(),temp.end(),0) > n)return;// 已经超了 直接停

    for(int i = deep+1;i<=n;i++)
    {
        temp.push_back(i);
        Helper(n, k, result,temp,i);
        temp.pop_back();
    }

    return ;
}
int main()
{
    int k = 3,n = 9;

    vector<vector<int>>result;
    vector<int>temp;

    for(int i = 1;i<=9;i++)// 要求只能小于10
    {
        temp.push_back(i);// 首字母
        Helper(n,k,result,temp);
        temp.pop_back();
    }

    // return result;
    return 0;

}