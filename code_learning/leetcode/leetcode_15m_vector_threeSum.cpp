#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool comPar(const int a,const int b)
{
    return a<b;
}

void threeSum(vector<int> &nums)
{
    vector<vector<int>> output;
    vector<int>result;
    // 先排序？ 如果都大于0直接return
    sort(nums.begin(),nums.end(),comPar);
    // if(nums[0]>=0) return output;
    // if(nums.size()<3) return output;
    // 1、三个循环暴力破解 只要判断到0位置即可停止
    // 2、双指针思想
    int left = 0,right = nums.size()-1;
    int temp = left + 1;

    while(left < right)
    {
        int twoSum = nums[left] + nums[right];
        // 如果小于零 需要在正数里面挑一个
        while(twoSum < 0)
        {
            temp = right - 1;
            if(nums[temp]>0 && twoSum+nums[temp] == 0)
            {
                result.push_back(nums[left]);
                result.push_back(nums[temp]);
                result.push_back(nums[right]);
                output.push_back(result);
                result.clear();
                result.shrink_to_fit();
                // 成功了之后可以让左侧加1 因为不能有重复答案
                left += 1;
            }
            else if(nums[temp]>0 && twoSum+nums[temp] > 0)
            {
                temp -= 1;
            }
            // 负数太大
            else
            {
                left += 1;
            }
            twoSum = nums[left] + nums[right];
        }
        while(twoSum > 0)
        {
            temp = left + 1;

            if(nums[temp]<0 && twoSum+nums[temp] == 0)
            {
                result.push_back(nums[left]);
                result.push_back(nums[temp]);
                result.push_back(nums[right]);
                output.push_back(result);
                result.clear();
                result.shrink_to_fit();
                // 成功了之后可以让右侧减小1 因为不能有重复答案
                right -= 1;
            }
            else if(nums[temp]<0 && twoSum+nums[temp] < 0)
            {
                temp += 1;
            }
            // 正数太大
            else
            {
                right -= 1;
            }
            twoSum = nums[left] + nums[right];
        }
        temp = left + 1;
        while(twoSum == 0)
        {
            if(nums[temp] == 0)
            {
                result.push_back(nums[left]);
                result.push_back(nums[temp]);
                result.push_back(nums[right]);
                output.push_back(result);
                result.clear();
                result.shrink_to_fit();
                // 成功了之后可以让右侧减小1 因为不能有重复答案
                right -= 1;
            }
            else
                temp += 1;
            twoSum = nums[left] + nums[right];
        }

    }
    return ;
}


int main()
{
    // 首先准备好nums target
    vector<int> nums {-1,0,1,2,-1,-4};
    threeSum(nums);// 引用左值

    return 0;
}