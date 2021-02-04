#include <iostream>
#include <algorithm>
#include "treeNode.h"
#include <numeric>
#include <set>

using namespace std;
/* -------------------------------------------
 * 二叉树部分
 * 首先对DFS要有了解
 * 难点在于使用set与tree-vector进行筛选与保存结果
 * 亮点：
 * set.count(a); 集合中是否存在a这个数
 * ------------------------------------------*/

typedef treeNode_2 TreeNode;
/* -------------------------------------------
 *    0
 *   / \
 *  1   4
 *     / \
 *    3   1
 *   /
 *  2
 * ------------------------------------------*/
TreeNode* initTree(TreeNode* &root)
{
    root->left = new TreeNode;
    root->right= new TreeNode;
    // 此时左右节点已经创建 下一步就是赋值
    root->left->val = 1;
    root->right->val = 4;

    root->right->left = new TreeNode;
    root->right->right = new TreeNode;

    root->right->left->val = 3;
    root->right->right->val = 1;

    root->right->left->left = new TreeNode;
    root->right->left->left->val = 2;
    return root;
}


int main()
{
    auto *root = new TreeNode;
    initTree(root);
    vector<int> temp;
    vector<double>result;

    // 创关键队列保存
    queue<treeNode_2 *> que;
    // 若不为空添加头结点进去
    if (root) que.push(root);
    // 直到所有遍历完成
    while (!que.empty()) {
        // 这里记住pop次数 到这里的时候queue中包含的都是此深度的所有节点值
        int size = que.size();
        // 这里一定要使用固定大小size，不要使用que.size()，因为que.size是不断变化的
        for (int i = 0; i < size; i++) {
            treeNode_2 *node = que.front();
            que.pop();
            temp.push_back(node->val);
            if (node->left) que.push(node->left);
            if (node->right) que.push(node->right);
        }
        result.push_back(1.0*accumulate(temp.begin(),temp.end(),0)/temp.size());
        temp.erase(temp.begin(),temp.end());
    }
    return 0;
}