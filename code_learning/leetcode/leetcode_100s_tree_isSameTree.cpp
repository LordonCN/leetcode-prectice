#include <iostream>
#include <algorithm>
#include <vector>
#include "treeNode.h"

using namespace std;
/* -------------------------------------------
 * ac 100 86
 * 掌握双向链表初始化
 * 掌握双向链表树结构的初始化
 * 相似 leetcode 110 111
 * offer 28 26 55 27
 * ------------------------------------------*/
typedef treeNode_2 TreeNode;

/* -------------------------------------------
 *    0
 *   / \
 *  10  10
 *   \ /
 *   5 5
 * ------------------------------------------*/
TreeNode* initTree(TreeNode* &root)
{
    root->left = new TreeNode;
    root->right= new TreeNode;
    // 此时左右节点已经创建 下一步就是赋值
    root->left->val = 10;
    root->right->val = 10;

    root->left->right = new TreeNode;
    root->right->left = new TreeNode;

    root->left->right->val = 5;
    root->right->left->val = 5;

    return root;
}

bool same(TreeNode* root1,TreeNode* root2)
{
    if(!root1 && !root2)return true;
    if(root1 && root2)
    {
        bool left = same(root1->left,root2->left);
        bool right = same(root1->right,root2->right);
        return (root1->val == root2->val)&&left&&right;// 关键加上值判断
    }
    return false;
}

// 此题目还可以用来判断两棵树是不是镜像的  只要交换左右即可
bool isSameTree(TreeNode* p, TreeNode* q) {
    if(!p && !q) return true;
    else if(!p && q)return false;
    else if(p && !q)return false;
    else{
        bool left = same(p->left,q->left);
        bool right = same(p->right,q->right);
        return left&&right&&(p->val == q->val);// 还有这里
    }

}

int main()
{
    TreeNode *root= new TreeNode;
    root = initTree(root);
//    bool result = false;
//
//    result = isSameTree(root);
    vector<int>result;
    treeQianxuDigui(root,result);

    return 0;
}