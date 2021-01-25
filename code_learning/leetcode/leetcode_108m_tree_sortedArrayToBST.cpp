#include <iostream>
#include <algorithm>
#include <vector>
#include "treeNode.h"

using namespace std;
/* -------------------------------------------
 * 二叉平衡搜索树部分
 * ------------------------------------------*/

typedef treeNode_2 TreeNode;

/* -------------------------------------------
 *    0
 *   / \
 * -3  9
 *  /  /
 * -10 5
 * ------------------------------------------*/
void sortedArrayToBST(TreeNode* &root,int left,int right,vector<int> &array)
{
    // 特殊情况
    if(!array.size()) return;
    // 2个的特殊情概况
    if(left>=right) return;

    // 第一次不new
    if(!root) root = new TreeNode;

    int middle = (left+right)/2;
    root->val = array[middle];

    sortedArrayToBST(root->left,left,middle,array);
    sortedArrayToBST(root->right,middle+1,right,array);
}


int main()
{
    vector<int> array;
    array.push_back(-10);
    array.push_back(-3);
//    array.push_back(-1);
    array.push_back(0);
    array.push_back(5);
    array.push_back(9);

    // 坑1：如果不new 会有节点创建错误
    TreeNode *root = new TreeNode;

    sortedArrayToBST(root,0,array.size(),array);

    return 0;
}