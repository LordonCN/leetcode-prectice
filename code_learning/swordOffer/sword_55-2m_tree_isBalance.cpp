#include <vector>
#include <iostream>
#include "treeNode.h"

using namespace std;
typedef treeNode_2 TreeNode;

TreeNode* inittree(TreeNode*root)
{
    root->val = 3;
    root->left = new TreeNode;
    root->right= new TreeNode;

    root->left->val = 9;
//    root->left->left = new TreeNode;
//    root->left->left->val= 11;
//    root->left->left->left = new TreeNode;
//    root->left->left->right = new TreeNode;
//    root->left->left->left->val=7;
//    root->left->left->right->val = 2;

    root->right->val = 20;
    root->right->left = new TreeNode;
    root->right->right= new TreeNode;
    root->right->left->val=15;
    root->right->right->val=7;
//    root->right->right->left= new TreeNode;
//    root->right->right->right= new TreeNode;
//    root->right->right->left->val=5;
//    root->right->right->right->val=1;

    return root;
}

int deephelper(TreeNode* root)
{
    if(root)
    {
        int leftd = deephelper(root->left);
        int rightd = deephelper(root->right);
        return leftd>rightd?leftd+1:rightd+1;
    }
    return 1;
}

bool balance(TreeNode* root) {

    if(root)
    {
        bool otherl = balance(root->left);
        bool otherr = balance(root->right);
        int left = deephelper(root->left);
        int right = deephelper(root->right);
        return abs(left-right)>1?false:true && otherl && otherr;
    }
    return true;
}

int main()
{
    TreeNode* root = new TreeNode;
    inittree(root);

    balance(root);

    return 0;
}
