#include <iostream>
#include <algorithm>
#include <vector>
#include "treeNode.h"
#include <stack>
#include <queue>

using namespace std; 
/* -------------------------------------------
 * 2.6回顾树相关内容
 * DFS的递归实现以及栈实现 层序遍历实现
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
void initTree(TreeNode* &root)
{
//    root = new TreeNode;
    root->val = 0;

    root->left = new TreeNode;
    root->left->val = 1;

    root->right= new TreeNode;
    root->right->val = 10;

    root->right->left= new TreeNode;
    root->right->left->val= 3;

    root->right->right= new TreeNode;
    root->right->right->val= 1;

    root->right->left->left= new TreeNode;
    root->right->left->left->val=2;
}

// 链表引用传递不能const
void DFS_Digui(TreeNode* &root,vector<int>&result)
{
    if(root)
    {
        result.push_back(root->val);
        DFS_Digui(root->left,result);
        DFS_Digui(root->right,result);
    }
    return;
}

void DFS_Stack(TreeNode* &root,vector<int>&result)
{
    if(!root) return ;

    stack<TreeNode*>sta;
    sta.push(root);
    while(!sta.empty())
    {
        TreeNode* temp = sta.top();
        result.push_back(temp->val);

        sta.pop();
        if(temp->right) sta.push(temp->right);
        if(temp->left) sta.push(temp->left);
    }

}

void BFS_Queue(TreeNode* &root,vector<int>&result)
{
    if(!root)return;
    queue<TreeNode*>que;
    que.push(root);
    while(!que.empty())
    {
        TreeNode* temp = que.front();
        result.push_back(temp->val);
        que.pop();

        if(temp->left) que.push(temp->left);
        if(temp->right) que.push(temp->right);
    }

}

int main()
{
    TreeNode *root= new TreeNode;
    initTree(root);
    vector<int> result;

//    DFS_Digui(root,result);
//    DFS_Stack(root,result);
    BFS_Queue(root,result);
    result = treeBFS(root);


    return 0;
}