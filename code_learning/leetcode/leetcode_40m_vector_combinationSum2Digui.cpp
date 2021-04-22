#include <iostream>
#include <vector>

using namespace std;

/* -------------------------------------------
 * vector题目 ac 9 34
 * 相似：39题 直接在39基础上修改后出现最后结果中存在重复的情况 此处添加vector清除重复元素部分
 * 亮点：
 * 清除vector中重复元素 1d 2d都可以
 * 最后遍历数组到集合中，然后迭代器加回vector 虽然麻烦 但是用的方法多:P
 * ------------------------------------------*/
void combinHelper(const vector<int>&nums,int target,vector<vector<int>>&result,vector<int>&temp,int pos)
{
    // 3 stop
    if(target == 0){
        if(!result.empty() && temp == result.back())return;
        result.push_back(temp);
        return ;
    }
    // 2 step
    for(int i = pos;i<nums.size();i++){
        if(target>=nums[i])
        {
            temp.push_back(nums[i]);
            combinHelper(nums,target-nums[i],result,temp,i+1);
            temp.pop_back();
        }
    }
    return ;
}

vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
    // 逆序排序
    sort(nums.begin(),nums.end(),[](int a,int b){return a>b;});
    vector<vector<int>>result;
    vector<int>temp;
    int startPos = 0;// 因为之前逆序排列了
    for(int i = 0 ;i <nums.size();i++)
    {
        // 找到一个比number大的数
        if(target>=nums[i])
        {
            startPos = i;
            break;
        }
    }
    // 1 kaishi
    combinHelper(nums,target,result,temp,startPos);

    // 结果处理
    set<vector<int>>out;
    for(int i = 0;i<result.size();i++)
        out.insert(result[i]);
    result.erase(result.begin(),result.end());
    set<vector<int>>::iterator ite = out.begin();
    for(;ite!=out.end();ite++)
        result.push_back(*ite);

    return result;
}