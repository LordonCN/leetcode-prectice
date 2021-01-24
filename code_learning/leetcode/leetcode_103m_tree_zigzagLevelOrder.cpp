#include <iostream>
#include <algorithm>
#include <vector>
#include "treeNode.h"

using namespace std;
/* -------------------------------------------
 * 在102的基础上只要获取树的深度然后将vector reverse即可
 * 同107 直接在result最外围reverse
 * ------------------------------------------*/

typedef treeNode_2 TreeNode;

/* -------------------------------------------
 *    0
 *   / \
 *  1  10
 *   \ /
 *   5 85
 * ------------------------------------------*/
TreeNode* initTree(TreeNode* &root)
{
    root->left = new TreeNode;
    root->right= new TreeNode;
    // 此时左右节点已经创建 下一步就是赋值
    root->left->val = 1;
    root->right->val = 10;

    root->left->right = new TreeNode;
    root->right->left = new TreeNode;

    root->left->right->val = 5;
    root->right->left->val = 85;

    return root;
}


void treeZigzagDFS_2d(treeNode_2* root,vector<vector<int>>& result,int level,int &maxDeep) {
    if(!root) return ;
    // 1、首先要添加进去一个空的 要不找不到这块内存
    if (level >= result.size())
        result.push_back(vector<int>());

    result[level].push_back(root->val);

    // 2、直接调用
    treeZigzagDFS_2d(root->left,result,level+1,maxDeep);
    treeZigzagDFS_2d(root->right,result,level+1,maxDeep);
    maxDeep = max(maxDeep,level);
}

int main()
{
    TreeNode *root= new TreeNode;
    root = initTree(root);
    // 广度优先搜索 层次遍历 二维数组
    vector<vector<int>> result_BFS2d;
    // 广度优先搜索 BFS 一维数组
    vector<int> result_BFS;
    // 深度优先搜索 DFS 二维数组
    vector<vector<int>> result_DFS2d;
    int maxDeepth = 0;

    char choice = 'C';
    switch(choice)
    {
        case 'A':
            result_BFS2d = treeBFS_2d(root);
            break;
        case 'B':
            result_BFS = treeBFS(root);
            break;
        case 'C':
            treeZigzagDFS_2d(root,result_DFS2d,0,maxDeepth);
            break;
        default:
            break;

    }
    // 取巧 直接reverse
    for(int i = 0 ;i <= maxDeepth;i++)
    {
        if (i%2)
            std::reverse(result_DFS2d[i].begin(),result_DFS2d[i].end());
    }


    return 0;
}