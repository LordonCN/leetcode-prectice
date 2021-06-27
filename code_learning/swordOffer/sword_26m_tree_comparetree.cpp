#include <iostream>
#include <algorithm>
#include "treeNode.h"

using namespace std;

typedef treeNode_2 TreeNode;

/* -------------------------------------------
 *    0
 *   / \
 *  10  6
 *  /\
 *  1 5
 * ------------------------------------------*/
TreeNode* initTree(TreeNode* &root)
{
    root->left = new TreeNode;
    root->right= new TreeNode;
    // 此时左右节点已经创建 下一步就是赋值
    root->left->val = 10;
    root->right->val = 6;

    root->left->right = new TreeNode;
    root->left->left = new TreeNode;

    root->left->right->val = 5;
    root->left->left->val = 1;

    return root;
}

TreeNode* initTree1(TreeNode* &root)
{
    root->val = 10;
    root->left = new TreeNode;
    // 此时左右节点已经创建 下一步就是赋值
    root->left->val = 1;

    return root;
}

/* -------------------------------------------
 *  想复杂了 但是条件都考虑全了 还有两个没有过
 *  无ac 待反攻
 * ------------------------------------------*/
bool helper(TreeNode* A,TreeNode* B)
{
    if(!A && !B)return false;// 到底还有没有
    else if(A && !B)return true;
    else if(!A && B)return false;
        // 找到AB的起始判断点
    else if(A->val != B->val)
    {
        if(helper(A->left,B)) return true;
        else if(helper(A->right,B)) return true;
        else return false;
    }
    else
    {
        if(!B->left && !B->right) return true;//B到这里没有啦
        else
        {
            if(helper(A->left,B->left)) return true;
            else if(helper(A->right,B->right)) return true;
            else return false;
        }
    }
}

bool compare(TreeNode* A,TreeNode* B)
{
    bool result = false;

    if(!A && !B)return true;
    else if(A && !B)return false;
    else if(!A && B)return false;

    // 特殊条件判断完进入递归
    // methord 1:
//    result = helper(A,B);


    // methord 2:
    if(A->val == B->val)
        return compare(A->left,B->left) && compare(A->right,B->right) ||
            compare(A->left,B) || compare(A->right,B);
    else
        return compare(A->left,B) || compare(A->right,B);


    return result;
}

int main()
{
    TreeNode *root= new TreeNode;
    root = initTree(root);
    TreeNode *son= new TreeNode;
    son = initTree1(son);

    compare(root,son);

    return 0;
}
