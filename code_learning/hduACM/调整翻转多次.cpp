#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n= 0,k = 0;
    cin >> n>>k;
    vector<int>nums(n,0);
    for(int i = 0;i<n;i++)
    {
        nums[i] = i+1;
    }
    vector<vector<int>>oper(k,vector<int>(2,0));
    for(int i = 0;i<k;i++)
    {
        cin>>oper[i][0]>>oper[i][1];
    }
    for(int i = 0;i<oper.size();i++)
    {
        reverse(nums.begin()+oper[i][0]-1,nums.begin()+oper[i][1]);
    }

    return 0;
}
