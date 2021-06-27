#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*************************************************************************
 * 测试一下哈希表空间复杂度是多少 O(1) ac 44 9
 *======================================================================*/
void offer56(vector<int>&nums)
{
    // hash方法
    vector<int>resulthash;
    unordered_map<int,int>hash;
    for(int i : nums)
        hash[i] += 1;
    for(auto [c,v] : hash)
        if (v == 1) resulthash.push_back(c);

    return ;
}

// 位运算
// 此处重点是根据异或结果对整个区间进行分组
vector<int> singleNumbers(vector<int>& nums) {
    int x = 0, y = 0, n = 0, m = 1;
    for(int num : nums)         // 1. 遍历异或
        n ^= num;
    while((n & m) == 0)         // 2. 循环左移，计算 m,值为异或结果中1出现的最低位 【很关键，分组依据】
        m <<= 1;
    for(int num : nums) {       // 3. 遍历 nums 分组
        if(num & m)
            x ^= num;           // 4. 当 num & m != 0 ，nums中有m这个组成时 放到X中
        else
            y ^= num;           // 4. 当 num & m == 0
    }
    return vector<int> {x, y};  // 5. 返回出现一次的数字
}

int main()
{
    vector<int> nums{1,1,4,6,3,7,3,7};
    offer56(nums);

    return 0;
}