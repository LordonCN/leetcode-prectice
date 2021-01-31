#include <iostream>
#include <vector>

using namespace std;

/* -------------------------------------------
 * vector题目 贪婪
 * 亮点：
 * tmep.erase迭代器清除vector内容
 * ------------------------------------------*/

void combinSum(const vector<int>&nums,int number)
{
    vector<vector<int>>result;
    vector<int>temp;

    int startPos;
    // 寻找可以开始进行做差的地方 不用后面再遍历
    for(int i = 0 ;i < nums.size();i++)
    {
        if(nums[i]<=number)
        {
            startPos = i;
            break;
        }
    }

    // 外循环逐步向右移动 取得到的最大值不断减小
    for(int epoch = startPos;epoch<nums.size();epoch++)
    {
        int target = number;
        temp.erase(temp.begin(),temp.end()); // vector要清零 这里用迭代器擦除
        // 内循环添加自减数值 保存结果
        for(int i = epoch;i< nums.size();i++)
        {
            while(target >= nums[i])
            {
                target -= nums[i];
                temp.push_back(nums[i]);
            }
            if(!target)
            {
                result.push_back(temp);
                break;
            }
        }
    }
    int i = 1;
    return ;
}

int main()
{
    // 首先准备好nums target
    vector<int> nums {1,2,3,7,8};

    // 逆序排序
    sort(nums.begin(),nums.end(),[](int a,int b){return a>b;});
    int target = 6;

    if(nums[nums.size()-1]>target) ;

    combinSum(nums,target);

    return 0;
}