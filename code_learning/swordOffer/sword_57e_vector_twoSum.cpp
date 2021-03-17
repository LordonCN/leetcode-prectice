int lastRemaining(int n, int target) {
    // 超时了
    vector<int>store;
    // 存储起来
    for(int i = 0;i<n;i++)
        store.push_back(i);

    int deletePos = 0;
    while(store.size() != 1)
    {
        int step = 1;
        while(step++<target)
        {
            if(deletePos == store.size())deletePos = 0;
            deletePos += 1;
            if(deletePos == store.size())deletePos = 0;
        }
        store.erase(store.begin()+deletePos);
    }

    return store[0];

}


offer57
#include <iostream>
#include <vector>

using namespace std;

/* -------------------------------------------
 * 双指针
 * ------------------------------------------*/

vector<int> twoSum(vector<int>& nums, int target) {
    int l = 0,r = nums.size()-1;
    vector<int>result;
    while(l<r)
    {
        int nowSum = nums[l] + nums[r];
        if(nowSum > target)r -= 1;
        else if(nowSum < target)l+=1;
        else
        {
            result.push_back(nums[l]);
            result.push_back(nums[r]);
            break;
        }
    }
    return result;
}

int main()
{
    vector<int> nums {1,3,5,7,9};

    int target = 6;
//    result = maxSubArrayTanxin(nums);
    twoSum(nums,target);

    return 0;
}
