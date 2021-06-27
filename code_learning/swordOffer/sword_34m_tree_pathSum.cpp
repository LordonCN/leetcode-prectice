#include <vector>
#include <iostream>
#include "treeNode.h"

using namespace std;
typedef treeNode_2 TreeNode;

TreeNode* inittree(TreeNode*root)
{
    root->val = 5;
    root->left = new TreeNode;
    root->right= new TreeNode;

    root->left->val = 4;
    root->left->left = new TreeNode;
    root->left->left->val= 11;
    root->left->left->left = new TreeNode;
    root->left->left->right = new TreeNode;
    root->left->left->left->val=7;
    root->left->left->right->val = 2;

    root->right->val = 8;
    root->right->left = new TreeNode;
    root->right->right= new TreeNode;
    root->right->left->val=13;
    root->right->right->val=4;
    root->right->right->left= new TreeNode;
    root->right->right->right= new TreeNode;
    root->right->right->left->val=5;
    root->right->right->right->val=1;

    return root;
}

void helper(vector<vector<int>>& result,vector<int> temp,TreeNode* root,int sum)
{
    int now = sum;
    if(root)
    {
        temp.push_back(root->val);
        now = now-root->val;
        helper(result,temp,root->left,now);
        helper(result,temp,root->right,now);
        if(now == 0)result.push_back(temp);
    }
    return;
}

vector<vector<int>> pathSum(TreeNode* root, int sum) {

    vector<vector<int>>result;
    vector<int>temp;
    if(root)// 从根节点开始进行求和
    {
        helper(result,temp,root,sum);
    }
    if(result[0].size() == 1)
        result.erase(result.begin(),result.begin()+1);
    return result;
}

int main()
{
    TreeNode* root = new TreeNode;
    inittree(root);
    int sum = 22;

    pathSum(root,sum);

    return 0;
}
