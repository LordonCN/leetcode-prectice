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
 * 递归求最大深度
 * 多了一个提前终止的判断
 * ------------------------------------------*/
int getDeepth(TreeNode* &root )
{
    // 空也是返回true
    if(root)
    {
        int ldeepth = getDeepth(root->left);
        int rdeepth = getDeepth(root->right);
        // 其中每一个子节点都要成立
        if(abs(ldeepth-rdeepth)>1 || ldeepth == -1 || rdeepth == -1) return -1;
        // 如果相等或者右侧大 得返回右侧计数 求最大深度 叶子节点的话就又+1
        return ldeepth>rdeepth? ldeepth+1:rdeepth+1;
    }
    return 0;

}

/* -------------------------------------------
 * 判断左右深度是否高度差在1以内
 * ------------------------------------------*/
bool isBalance(TreeNode* &root)
{
    if(!root) return true;

    int left = getDeepth(root->left);
    int right = getDeepth(root->right);

    return abs(left-right)<=1 && left!=-1 && right!=-1;// 4.8默写这里忘掉了

}

int main()
{
    auto *root = new TreeNode;
    initTree(root);

    bool result;
    result = isBalance(root);

    return 0;
}