#include <iostream>
#include <algorithm>
#include "treeNode.h"

using namespace std;
/* -------------------------------------------
 * 平衡二叉树部分
 * 递归求最大深度 与111相反 与110相同
 * ------------------------------------------*/

typedef treeNode_2 TreeNode;

// 0625 复习
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(!root)return true;
        return dfs(root->left,root->right);
    }
    bool dfs(TreeNode* l,TreeNode* r)
    {
        if(!r && !l)return true;
        if((!l && r) || (l && !r))return false;
        if(l->val != r->val)return false;

        // 这两边都要验
        return dfs(l->left,r->right) && dfs(l->right,r->left);
    }
};


/* -------------------------------------------
 *    0
 *   /  \
 *  1    1
 *  /\    /\
 * 13 11  11 13
 * ------------------------------------------*/
TreeNode* initTree(TreeNode* &root)
{
    root->left = new TreeNode;
    root->right= new TreeNode;
    // 此时左右节点已经创建 下一步就是赋值
    root->left->val = 1;
    root->right->val = 1;

    root->left->left = new TreeNode;
    root->left->right = new TreeNode;
    root->left->left->val = 13;
    root->left->right->val = 11;

    root->right->left = new TreeNode;
    root->right->right = new TreeNode;

    root->right->left->val = 11;
    root->right->right->val = 13;


    return root;
}

bool help(TreeNode* lef,TreeNode* righ)
{
    if(lef && !righ)return false;
    else if(!lef && righ)return false;
    else if(!lef && !righ)return true;
    else if(lef->val != righ->val)return false;
    else
    {
        bool l = help(lef->left,righ->right);
        bool r = help(lef->right,righ->left);
        return (l&&r);
    }
}

bool isSymmetric(TreeNode* root) {

    if(root == NULL)return true;
    return help(root->left,root->right);
}

int main()
{
    auto *root = new TreeNode;
    initTree(root);

    isSymmetric(root);

    return 0;
}
