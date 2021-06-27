#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void dfs(TreeNode* root,vector<int>&nums)
{
    if(root)
    {
        nums.push_back(root->val);
        dfs(root->left,nums);
        dfs(root->right,nums);
    }
    return;
}

int kthLargest(TreeNode* root, int k) {
    vector<int>nums;
    dfs(root,nums);
    sort(nums.begin(),nums.end(),[](int a,int b){return a>b;});
    // cout<<nums[0];
    return nums[k-1];
}