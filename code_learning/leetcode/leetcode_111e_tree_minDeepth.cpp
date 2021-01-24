#include <iostream>
#include <algorithm>
#include "treeNode.h"

using namespace std;
/* -------------------------------------------
 * 二叉树部分
 * 递归求最小深度 与 110 104 相反
 * ------------------------------------------*/

typedef treeNode_2 TreeNode;
/* -------------------------------------------
 *    0
 *   / \
 *  1  10
 *     /\
 *    3  1
 *   /
 *  2
 * ------------------------------------------*/
TreeNode* initTree(TreeNode* &root)
{
    root->left = new TreeNode;
    root->right= new TreeNode;
    // 此时左右节点已经创建 下一步就是赋值
    root->left->val = 1;
    root->right->val = 10;

    root->right->left = new TreeNode;
    root->right->right = new TreeNode;

    root->right->left->val = 3;
    root->right->right->val = 1;

    root->right->left->left = new TreeNode;
    root->right->left->left->val = 2;

    return root;
}

/* -------------------------------------------
 * 递归求最小深度
 * ------------------------------------------*/
int getDeepth(TreeNode* &root )
{
    if(root)
    {
        int ldeepth = getDeepth(root->left);
        int rdeepth = getDeepth(root->right);

        // 最小深度遍历中需要加入左右子树是否存在的判断 因为在求最大深度中始终返回最大深度+1
        // 最小深度中存在一边为0的情况 然而此时不能返回小的一边
        if(!root->left && root->right)
            return rdeepth+1;
        if(root->left && !root->right)
            return ldeepth+1;

        // 这里是求最小值的关键
        return ldeepth>rdeepth?rdeepth+1:ldeepth+1;
    }
    return 0;

}

int main()
{
    auto *root = new TreeNode;
    initTree(root);

    int result;
    result = getDeepth(root);

    return 0;
}