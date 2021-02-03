#include <iostream>
#include <algorithm>
#include "treeNode.h"
#include <numeric>

using namespace std;
/* -------------------------------------------
 * 二叉树部分
 * 难点在于怎么随着递归更新数组
 * 前置声明一直有问题 放到类中就好使了
 * 难点：
 * 相互之间调用太多 耦合度有点高 难理解
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

class slocation{
public:
    int helper(int target,TreeNode* &root)
    {
        if(root)
        {
            return pathSum(target,root->left) + pathSum(target,root->right) +pathSum(target,root);
        }
        else
            return 0;
    }

    int pathSum(int target,TreeNode* &root)
    {
        if(!root) return 0;
        int count = root->val == target? 1:0;
        count += helper(target-root->val,root->left);
        count += helper(target-root->val,root->right);

        return count;
    }
};

int main()
{
    auto *root = new TreeNode;
    initTree(root);
    slocation s;

    int target = 5;
    int result = s.pathSum(target,root);

    return 0;
}