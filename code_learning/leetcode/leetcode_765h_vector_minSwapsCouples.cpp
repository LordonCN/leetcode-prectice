#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

/* -------------------------------------------
 * 贪婪算法
 * 复杂度为n 一次遍历
 * ------------------------------------------*/

// 0 2 1 3
// 0 1 2 3
void swapHelper(vector<int>&nums,int pos,unordered_map<int,int>hashmap)
{
    int temp = 0;
    if(nums[pos]%2 == 0)// 找+1的数
    {
        temp = nums[pos+1]; // 先把2 保存
        nums[pos+1] = nums[pos]+1; // 0 1 1 3
        nums[hashmap[nums[pos]+1]] = temp; // 0 1 2 3
        hashmap[temp] = hashmap[nums[pos]+1];
    }
    else
    {
        temp = nums[pos+1];
        nums[pos+1] = nums[pos]-1;
        nums[hashmap[nums[pos]-1]] = temp;
        hashmap[temp] = hashmap[nums[pos]-1];
    }

}

bool isCouple(vector<int>&nums,int i)
{
    //两个数字连续且大的是奇数
    return abs(nums[i]-nums[i+1]) == 1 && max(nums[i],nums[i+1])%2 == 1;
}

int minSwap(vector<int> &nums)
{
    int result = 0;
    // 1.将每一次位置都记录
    unordered_map<int,int>hashmap;
    for(int i = 0;i<nums.size();i++)
        hashmap[nums[i]] = i;

    // 2.重头遍历 判断是否满足条件 进行交换
    for(int i = 0;i<nums.size();i+=2)
    {
        if(isCouple(nums,i)); // 0,1
        else
        {
            swapHelper(nums,i,hashmap); //1,2
            result++;
        }
    }
    return result;
}

int main()
{
    vector<int> nums{0,2,1,3,5,7,6,4};


    int result;
    result = minSwap(nums);

    return 0;
}