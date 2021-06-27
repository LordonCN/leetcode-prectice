#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*************************************************************************
 * 第二题 ac 89 84 3.4
 *======================================================================*/
 // 先排序再遍历也是很快的
void offer56_2(vector<int>&nums)
{
    vector<int>resultsort;
    sort(nums.begin(),nums.end());
    for(int i = 0 ;i<nums.size()-2;i++)
    {
        if(nums[i] == nums[i+1])
            i += 2;
        else
        {
            resultsort.push_back(nums[i]);
            break;
        }
    }
    if(resultsort.empty())
        resultsort.push_back(nums[nums.size()-1]);

    return ;
}

// 位操作 统计所有数字为1的位 然后对3球余后取出来1
// 挺好的
int singleNumber(vector<int>& nums) {
    // 位操作
    vector<int> b(32, 0);// 数组计数 位为1的个数
    for (int i : nums)// 取数字
    {
        for (int j = 0; i != 0; ++j) // 如果该数字不为0 将其所有为1的位进行统计
        {
            if ((i & 1) == 1)
            {
                ++b[j];
            }
            i >>= 1;
        }
    }
    int ans = 0;
    unsigned int base = 1;
    for (int i = 0; i < 32; ++i)
    {
        if (b[i] % 3 == 1)// 对统计结果每一位进行对3求余
        {
            ans |= base;// 把剩余的1全部取出来
        }
        base <<= 1;
    }
    return ans;

}

int main()
{
    vector<int> nums{3,4,3,4,1,4,3};

    offer56(nums);

    return 0;
}