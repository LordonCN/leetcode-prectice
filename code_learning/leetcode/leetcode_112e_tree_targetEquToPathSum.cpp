#include <iostream>
#include <algorithm>
#include "treeNode.h"

using namespace std;
/* -------------------------------------------
 * 二叉树深度类型题目
 * DFS递归 深度遍历
 * 结合111中在遍历深度变化时的特殊条件判断
 * 叶子节点的判断条件
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
 * 递归 重点是寻找叶子节点
 * ------------------------------------------*/
void getDeepth(TreeNode* &root,vector<int> &result,int sumnuber)
{
    if(root)
    {
        sumnuber += root->val;

        getDeepth(root->left,result,sumnuber);
        getDeepth(root->right,result,sumnuber);
        // 关键 参考111中最小深度的判断条件
        if(!root->right && !root->left)
            result.push_back(sumnuber);
    }
}

bool isTargetSum(TreeNode* &root,int target)
{
    if(!root) return false;

    // 或者到根节点就append进去
    vector<int> result;

    getDeepth(root,result,0);

    for(int i = 0; i<result.size();i++)
    {
        if(target == result[i])
            return true;
    }

    return false;

}

int main()
{
    auto *root = new TreeNode;
    initTree(root);
    int target = 11;

    bool result;
    result = isTargetSum(root,target);

    return 0;
}