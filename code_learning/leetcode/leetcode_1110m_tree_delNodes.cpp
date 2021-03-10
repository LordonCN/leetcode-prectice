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

void delNodes(TreeNode* &root,vector<TreeNode*>&forest,set<int>&to_delete)
{
    // 3 叶子节点结束
    if(!root) return ;

    // 2 DFS递归搜索
    delNodes(root->left,forest,to_delete);
    delNodes(root->right,forest,to_delete);

    // 此节点判断完毕 判断当前root是否需要删除 如果删除要怎么做
    if(to_delete.count(root->val)) // 集合中存在该值
    {
        if(root->left)forest.push_back(root->left);
        if(root->right)forest.push_back(root->right);
        root = NULL;
    }
    return ;
}

int main()
{
    auto *root = new TreeNode;
    // 0
    initTree(root);
    // 存储tree类型树
    vector<TreeNode*>forest;
    vector<int>to_delete{4};
    set<int> SET{to_delete.begin(),to_delete.end()};

    // 1
    delNodes(root,forest,SET);
    // 4 最终把头加进来 因为没有顶部的添加操作
    if(root) forest.push_back(root);

    return 0;
}