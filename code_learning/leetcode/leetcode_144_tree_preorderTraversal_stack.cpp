#include <iostream>
#include <algorithm>
#include "treeNode.h"
#include <stack>

using namespace std;
/* -------------------------------------------
 * 二叉树部分
 * 递归深度 类型 与 112类似 考虑用vector保存
 * 94 中序遍历
 * 145 后序遍历
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
/* -------------------------------------------
 *    0
 *   / \
 *  1  10
 *  /\
 * 3  4
 *     \
 *      9
 * 使用栈实现递归功能
 * ------------------------------------------*/
vector<int> treeDFSStack(treeNode_2* root) {
    vector<int> result;
    if(!root) return result;

    stack<treeNode_2 *> sta;
    sta.push(root);
    // 直到所有遍历完成
    while (!sta.empty()) {
        // 这里记住pop次数 到这里的时候queue中包含的都是此深度的所有节点值
        treeNode_2 *node = sta.top();
        sta.pop();
        result.push_back(node->val);
        // 先push右 再push左 循环回来top就先取左 栈的机制 如果是队列的话就是先左再右 node取front
        if (node->right) sta.push(node->right);
        if (node->left) sta.push(node->left);
        }
    return result;
}

void flation(TreeNode* &root)
{
    if(!root) return ;

    vector<int> result;

    result = treeDFSStack(root);

}

int main()
{
    auto *root = new TreeNode;
    initTree(root);

    flation(root);

    return 0;
}