#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*************************************************************************
 * offer45 ac 15 95  3.3
 *======================================================================*/
string Utils::offer45(vector<int>& nums)
{
    // 根据首位 次位大小排序
    sort(nums.begin(),nums.end(),[](int a,int b){string l = to_string(a)+to_string(b);string r =to_string(b) + to_string(a);return l<r;});
    string s = "";
    for(auto i : nums)
        s += to_string(i);

    return s;
}

int main()
{
//    vector<vector<int>> nums{{21,3},{2,5}};
    vector<int> nums{1,2,3,40,46,42,5,6,7,8,9};

    findNumberIn2DArray(nums);

    return 0;
}