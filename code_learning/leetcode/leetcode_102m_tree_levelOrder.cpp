#include <iostream>
#include <algorithm>
#include <vector>
#include "treeNode.h"

using namespace std;
/* -------------------------------------------
 * 94 145 144
 * 深度搜索因为可以依靠二维数组的索引来添加内容 所以此题目用DFS BFS好用
 * 了解DFS BFS， 两种搜索方式在树的搜索顺序上略有不同
 * DFS 依靠递归进行搜索 像101题中就是先递归搜索最左侧树 然后向上返回搜索右子树 的动态图如下网址所示
 * https://leetcode-cn.com/problems/binary-tree-level-order-traversal/solution/bfs-de-shi-yong-chang-jing-zong-jie-ceng-xu-bian-l/
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
            treeDFS_2d(root,result_DFS2d,0);
            break;
        default:
            break;

    }

    return 0;
}