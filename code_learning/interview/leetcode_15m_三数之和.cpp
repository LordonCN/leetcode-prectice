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

// 1- 单循环双指针
// 不错挺好的 简洁
vector<vector<int>> threeSum(vector<int>& nums) {
    sort(nums.begin(),nums.end());
    vector<vector<int>>out;
    if(nums.size()<3)return out;
    vector<int>temp;
    int len = nums.size();
    int sum;
    for(int l = 0;l<len-2;l++)
    {
        if(l>0 && nums[l]==nums[l-1])continue;
        int m = l + 1;// 中间指针左侧向右移动
        int r = len - 1;// 右侧指针从右向左移动
        while(m < r){
            sum = nums[l] + nums[m] + nums[r];
            if(sum == 0){
                temp.push_back(nums[l]),temp.push_back(nums[m++]), temp.push_back(nums[r--]);
                out.push_back(temp);
                temp.erase(temp.begin(),temp.end());
                // 如果存在m r相等值 直接跳过
                while(m < r && nums[m] == nums[m - 1]) m++;
                while(m < r && nums[r] == nums[r + 1]) r--;
            }
            // 两指针向中间移动
            else if(sum < 0) m++;
            else r--;
        }
    }
    return out;
}


// 0 - 超时：三指针遍历 加入相同值跳过 暴力法搜索为 O(N3)O(N3) 时间复杂度，可通过双指针动态消去无效解来优化效率
vector<vector<int>> threeSum(vector<int>& nums) {
    sort(nums.begin(),nums.end());
    vector<vector<int>>out;
    if(nums.size()<3)return out;
    vector<int>temp;
    int len = nums.size();
    int sum;
    for(int l = 0;l<len-2;l++)
    {
        if(l>0 && nums[l]==nums[l-1])continue;
        for(int m = l+1;m<len-1;m++)
        {
            if(m>l+1 && nums[m]==nums[m-1])continue;
            sum = nums[m] + nums[l];
            if(sum+nums[m+1]>0)break;// 最小的两个数都加起来为0 直接结束算了

            for(int r = m+1;r<len;r++)
            {
                if(r>m+1 && nums[r]==nums[r-1])continue;
                sum += nums[r];
                // cout<<sum<<endl;
                if(sum>0)// 最小的两个数都加起来为0 直接结束算了
                {
                    // 回到中间m循环中
                    break;
                }
                if(sum == 0){
                    temp.push_back(nums[l]),temp.push_back(nums[m]),temp.push_back(nums[r]);
                    out.push_back(temp);
                    temp.erase(temp.begin(),temp.end());
                    break;
                }
                sum -= nums[r];
            }
        }
        // if(!temp.empty())temp.erase(temp.begin(),temp.end());
    }
    return out;
}

int main()
{
    // 首先准备好nums target
    vector<int> nums {-1,0,1,2,-1,-4};
    threeSum(nums);// 引用左值

    return 0;
}