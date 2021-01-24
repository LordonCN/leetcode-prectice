#include <iostream>
#include <algorithm>
#include <vector>
#include "treeNode.h"

using namespace std;
/* -------------------------------------------
 * 掌握双向链表初始化
 * 掌握双向链表树结构的初始化
 * 明确递归结束条件的判断
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

/* -------------------------------------------
 * 递归判断是否对称 终止条件为空的判断
 * ------------------------------------------*/
bool compare(TreeNode* &left,TreeNode* &right)
{
    // 对称迭代到最后是这个结果
    if(!left && !right) return true;
    // 不对称判断
    else if (left && !right) return false;
    else if (!left && right) return false;
    // 上面三个判断之后 left right都存在 那么剔除掉值不相同的
    else if (left->val != right->val) return false;

    // 其余的肯定相同 那么继续向下迭代
    bool leftOK = compare(left->left,left->right);
    bool rightOK = compare(right->left,right->right);


    return leftOK && rightOK;
}

int main()
{
    TreeNode *root= new TreeNode;
    root = initTree(root);
    bool result = false;
    //  特殊判断 如果头为空
//    if(!root) return true;

    result = compare(root->left,root->right);

    return 0;
}