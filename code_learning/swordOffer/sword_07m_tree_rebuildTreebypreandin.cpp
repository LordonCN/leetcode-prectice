#include <iostream>
//#include "listNode.h"
#include <vector>
#include <algorithm>
#include "treeNode.h"

using namespace std;

/* -------------------------------------------
 * 前序与中序重新构造树
 * 递归实现 涉及数组索引分割 易混
 * ------------------------------------------*/
typedef treeNode_2 TreeNode;

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

    // 初始化当前高度下的root
    if(!preorder.size() || !inorder.size())return NULL;
    TreeNode* root = new TreeNode;
    root->val = preorder[0];
    int idx;
    for(int i = 0;i<inorder.size();i++)
    {
        if(inorder[i]==root->val)idx = i;
    }
    // 截取的话只能重新创建vector
    // pre(1:1+idx) in(:idx)
    vector<int> L_pre(preorder.begin() + 1, preorder.begin() + idx + 1);
    vector<int> L_in(inorder.begin(), inorder.begin() + idx);
    root->left = buildTree(L_pre, L_in);

    // pre(1+idx:) in(1+idx:)
    vector<int> R_pre(preorder.begin() + idx + 1, preorder.end());
    vector<int> R_in(inorder.begin() + idx + 1, inorder.end());
    root->right = buildTree(R_pre, R_in);

    return root;
}

int main()
{

    vector<int>preorder{3,9,20,15,7};
    vector<int>inorder{9,3,15,20,7};

    TreeNode* root = buildTree(preorder, inorder);


    return 0;
}
