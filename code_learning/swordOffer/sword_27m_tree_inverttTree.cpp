#include <iostream>
#include <algorithm>
#include "treeNode.h"

using namespace std;
/* -------------------------------------------
 * 平衡二叉树部分
 * 递归求最大深度 与111相反 与110相同
 * ------------------------------------------*/

typedef treeNode_2 TreeNode;
/* -------------------------------------------
 *    0
 *   /  \
 *  1    10
 *  /\     /\
 * 13 11   3  1
 * ------------------------------------------*/
TreeNode* initTree(TreeNode* &root)
{
    root->left = new TreeNode;
    root->right= new TreeNode;
    // 此时左右节点已经创建 下一步就是赋值
    root->left->val = 1;
    root->right->val = 10;

    root->left->left = new TreeNode;
    root->left->right = new TreeNode;
    root->left->left->val = 13;
    root->left->right->val = 11;

    root->right->left = new TreeNode;
    root->right->right = new TreeNode;

    root->right->left->val = 3;
    root->right->right->val = 1;


    return root;
}

TreeNode* invertTree(TreeNode* root) {
    if(!root)
        return root;
    swap(root->left,root->right);
    invertTree(root->left);
    invertTree(root->right);
    return root;
}

int main()
{
    auto *root = new TreeNode;
    initTree(root);

    invertTree(root);

    return 0;
}
