#include <iostream>
#include "treeNode.h"

using namespace std;
typedef treeNode_2 TreeNode;

/* -------------------------------------------
 * 前序 中序 后续遍历树 每一个子树也都要按照这个原理读取
 * 都是用递归 DFS方法 关键就是在递归的时候哪个位置上append 读数
 * 使用引用修改vector容错率低
 * ------------------------------------------*/
/* -------------------------------------------
 *    0
 *   / \
 *  10  1
 *  /\  /\
 * 9 15 5 2
 * ------------------------------------------*/
TreeNode* initTree(TreeNode* &root)
{
    root->left = new TreeNode;
    root->right= new TreeNode;
    // 此时左右节点已经创建 下一步就是赋值
    root->left->val = 10;
    root->right->val = 1;

    root->left->left= new TreeNode;
    root->left->right = new TreeNode;
    root->right->left = new TreeNode;
    root->right->right= new TreeNode;

    root->left->left->val = 9;
    root->left->right->val = 15;
    root->right->left->val = 5;
    root->right->right->val = 2;

    return root;
}

/* -------------------------------------------
 * 前序遍历 [0,10,9,15,1,5,2]
 * ------------------------------------------*/
void preOrder(TreeNode* &pre,vector<int> &result)
{
    if(pre)
    {
        result.push_back(pre->val);
        preOrder(pre->left,result);
        preOrder(pre->right,result);
    }
}

/* -------------------------------------------
 * 中序遍历 [9,10,15,0,5,1,2]
 * ------------------------------------------*/
void inOrder(TreeNode* &in,vector<int> &result)
{
    if(in)
    {
        inOrder(in->left,result);
        result.push_back(in->val);
        inOrder(in->right,result);
    }
}

/* -------------------------------------------
 * 后序遍历 [10,15,1,5,2,0] 错 这不对
 * [9,15,10,5,2,1,0]
 * ------------------------------------------*/
void posOrder(TreeNode* &pos,vector<int> &result)
{
    if(pos)
    {
        posOrder(pos->left,result);
        posOrder(pos->right,result);
        result.push_back(pos->val);
    }
}

int main()
{
    TreeNode* seedTree;
    initTree(seedTree);

    vector<int> output ;
    char number = 'C';

    switch(number)
    {
        case 'A':
            preOrder(seedTree,output);
            break;
        case 'B':
            inOrder(seedTree,output);
            break;
        case 'C':
            posOrder(seedTree,output);
            break;
        default:
            break;
    }



    return 0;
}