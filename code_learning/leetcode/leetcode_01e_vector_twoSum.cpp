#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

/* -------------------------------------------
 * hash 细节补充
 * 重点：
 * hash.find(A) != hash.end() 如果表中能够找到A这个键值则执行
 * hash[A] = key
 * ------------------------------------------*/

vector<int> twoSum(vector<int>& nums,int target)
{
    vector<int>result;
    unordered_map<int,int>hash;

    int i = 0;
    for(auto number:nums)
    {
        hash[number] = i++;
        if(hash.find(target-number) != hash.end())
        {
            result.push_back(hash[number]);
            result.push_back(hash[target-number]);
            return result;
        }
    }
    return result;
}

int main()
{
    // 首先准备好nums target
    vector<int> nums {7,9,0,1,2};
    int target = 10;

    twoSum(nums,target);

    return 0;
}