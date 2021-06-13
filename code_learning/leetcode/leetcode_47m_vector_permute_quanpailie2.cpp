#include <iostream>
#include <vector>
#include <set>

using namespace std;

/* -------------------------------------------
 * DFS深度 前序遍历
 * 添加了一个辅助状态判断数组sign 用来判断是否用过
 * 为了处理重复数组出现导致的多次重复遍历 可以排序一下然后优化TODO
 * ------------------------------------------*/
void DFS(set<vector<int>>&result,
         vector<int>temp,
         vector<int>sign,
         const vector<int>&nums)
{
    if(temp.size() == nums.size())
    {
        result.insert(temp);
        return;
    }
    for(int i = 0;i<sign.size();i++)
    {
        if(!sign[i])
        {
            temp.push_back(nums[i]);
            sign[i] = 1;
            DFS(result,temp,sign,nums);
            sign[i] = 0;
            temp.erase(temp.end()-1);
        }
    }
}


int main()
{
    set<vector<int>>result;
    vector<int>temp;
    vector<int>sign(nums.size(),0);
    DFS(result,temp,sign,nums);
    vector<vector<int>>output;
    for(set<vector<int>>::iterator ite = result.begin();ite!= result.end();ite++)
        output.push_back(*ite);

    // return output;
    return 0;
}