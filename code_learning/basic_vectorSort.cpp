#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// sort vector 二维数组排序
bool sortCmp(const vector<int>&a,const vector<int>&b)
{
    return a[0] > b[0]; // 升序 < 降序
}

// sort vector 一维数组排序
bool sortCmpReverse(const int a,const int b)
{
    return a > b; // 降序
}

vector<vector<int>> twoParts(vector<vector<int>> nums)
{
    sort(nums.begin(),nums.end(),sortCmp);

    return nums;
}


int main()
{
    // 首先准备好nums target
    vector<vector<int>> nums;
    nums.push_back({1,4});
    nums.push_back({7,8});
    nums.push_back({2,5});
    nums.push_back({10,13});

    vector<vector<int>>result;
    result = twoParts(nums);

    vector<int> array;
    array.push_back(0);
    array.push_back(1);
    array.push_back(2);
    array.push_back(3);
    array.push_back(7);
    array.push_back(8);
    array.push_back(8);
    array.push_back(8);
    array.push_back(9);
    sort(array.begin(),array.end(),sortCmpReverse);

    return 0;
}