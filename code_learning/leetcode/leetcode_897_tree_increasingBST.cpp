#include <iostream>
#include <algorithm>
#include "treeNode.h"

using namespace std;
/* -------------------------------------------
 * 二叉树部分
 * 递归深度 类型 与 112类似 考虑用vector保存
 * ------------------------------------------*/

typedef treeNode_2 TreeNode;
/* -------------------------------------------
 *    0
 *   / \
 *  1  10
 *  /\
 * 3  4
 *     \
 *      9
 * ------------------------------------------*/
TreeNode* initTree(TreeNode* &root)
{
    root->left = new TreeNode;
    root->right= new TreeNode;
    // 此时左右节点已经创建 下一步就是赋值
    root->left->val = 1;
    root->right->val = 10;

    root->left->left= new TreeNode;
    root->left->right= new TreeNode;

    root->left->left->val = 3;
    root->left->right->val = 4;

    root->left->right->right= new TreeNode;
    root->left->right->right->val = 9;
    return root;
}

TreeNode* increasingBST(TreeNode* root) {
    vector<int>nums;
    stack<TreeNode*>sta;
    while(root||!sta.empty())
    {
        while(root)
        {
            sta.push(root);
            root = root->left;
        }
        root = sta.top();
        sta.pop();
        nums.push_back(root->val);
        root = root->right;
    }

    TreeNode* s = new TreeNode;
    TreeNode* solder = new TreeNode;
    solder->right = s;
    for(int i = 0;i<nums.size();i++)
    {
        s->val = nums[i];
        if(i!=nums.size()-1)
        {
            s->right = new TreeNode;
            s = s->right;
        }
    }
    return solder->right;
}

int main()
{
    auto *root = new TreeNode;
    initTree(root);

    increasingBST(root);

    return 0;
}