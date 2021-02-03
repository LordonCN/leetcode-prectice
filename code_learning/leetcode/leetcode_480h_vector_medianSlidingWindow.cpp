#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

/* -------------------------------------------
 * vector题目
 * 亮点：
 * 不取引用操作排序会有浅拷贝*
 * ------------------------------------------*/

void medianSlidingWindow(const vector<int> nums,int number)
{
    // number/2 = 0时应该return accumulate(nums.begin(),nums.end(),0)*1.0/nums.size();
    // number/2 = 1时应该return sort(nums.begin(),nums.end()) 取 nums[i+k/2+1];
    vector<double>result;
    vector<int>temp;
    int epoch = number;
    while(epoch/2 != 0 || epoch != 1)
    {
        epoch /= 2;
    }

    if(epoch == 0)
    {
        // 奇数为例
        for(int i = 0;i <= nums.size()-number;i++)
        {
            temp = nums;
            sort(temp.begin()+i,temp.begin()+i+number);
            result.push_back(temp[i+number/2]);
        }
    }
    else
    {
        double caculate = 0;
        for(int i = 0;i <= nums.size()-number;i++)
        {
            caculate = accumulate(nums.begin()+i,nums.begin()+i+number,0);
            caculate = caculate*1.0/number;
            result.push_back(caculate);
        }

    }
    return ;
}

int main()
{
    // 首先准备好nums target
    vector<int> nums {1,3,-1,-3,5,3,6,7};

    // 逆序排序
    int target = 2;

    medianSlidingWindow(nums,target);

    return 0;
}