#include <iostream>
#include <vector>

using namespace std;

/* -------------------------------------------
 * vector题目 贪婪
 * 递归完成
 * ac 76 95
 * ------------------------------------------*/
void combinHelper(const vector<int>&nums,int target,vector<vector<int>>&result,vector<int>&temp,int pos)
{
    // 3 stop
    if(target == 0)
    {
        result.push_back(temp);
        return ;
    }
    // 2 step
    for(int i = pos;i<nums.size();i++)
    {
        if(target>=nums[i])
        {
            temp.push_back(nums[i]);
            combinHelper(nums,target-nums[i],result,temp,i);
            temp.pop_back();
        }
    }
    return ;
}

void combinSum(const vector<int>&nums,int number)
{
    vector<vector<int>>result;
    vector<int>temp;
    int startPos = 0;// 因为之前逆序排列了
    for(int i = 0 ;i <nums.size();i++)
    {
        // 找到一个比number大的数
        if(number>=nums[i])
        {
            startPos = i;
            break;
        }
    }
    // 1 kaishi
    combinHelper(nums,number,result,temp,startPos);

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