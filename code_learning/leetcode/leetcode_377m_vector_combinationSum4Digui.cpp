#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

/* -------------------------------------------
 * vector题目 超时 动态规划类似于爬台阶
 * 递归就先做到这里吧
 * 相似：39题 40 17 22 216
 * ------------------------------------------*/
void Helper(vector<int>aim,
            vector<vector<int>>&result,
            vector<int>&temp,
            int target)
{
    if(accumulate(temp.begin(),temp.end(),0) == target)
        result.push_back(temp);

    if(accumulate(temp.begin(),temp.end(),0) > target)return;

    for(int i = 0;i<aim.size();i++)
    {
        temp.push_back(aim[i]);
        Helper(aim,result,temp,target);
        temp.pop_back();
    }
    return ;
}

int combinationSum4(vector<int>& aim, int target) {
    vector<vector<int>>result;
    vector<int>temp;

    for(int i = 0;i<aim.size();i++)
    {
        temp.push_back(aim[i]);// 首字母
        Helper(aim,result,temp,target);
        temp.pop_back();
    }
    return result.size();
}