#include <iostream>
#include <vector>

using namespace std;

/* -------------------------------------------
 * vector题目 贪婪
 * 相似：39题 直接在39基础上修改后出现最后结果中存在重复的情况 此处添加vector清除重复元素部分
 * 亮点：
 * 清除vector中重复元素 1d 2d都可以
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
            combinHelper(nums,target-nums[i],result,temp,i+1);
            temp.pop_back();
        }
    }
    return ;
}

void combinSum(const vector<int>&nums,int number)
{
    vector<vector<int>>result;
    vector<int>temp;
    int startPos = 0;
    for(int i = 0 ;i <nums.size();i++)
    {
        if(number>=nums[i])
        {
            startPos = i;
            break;
        }
    }
    // 1 kaishi
    combinHelper(nums,number,result,temp,startPos);

    // 清除vector中重复元素
    vector<vector<int>>::iterator it,it1;
    for (it=++result.begin(); it != result.end();)
    {
        it1 = find(result.begin(),it,*it);    //若当前位置之前存在重复元素，删除当前元素,erase返回当前元素的下一个元素指针
        if(it1 != it)
            it=result.erase(it);
        else
            it++;
    }
    return ;
}

int main()
{
    // 首先准备好nums target
    vector<int> nums {10,1,2,7,6,1,5};

    // 逆序排序
    sort(nums.begin(),nums.end(),[](int a,int b){return a>b;});
    int target = 8;

    if(nums[nums.size()-1]>target) ;

    combinSum(nums,target);

    return 0;
}