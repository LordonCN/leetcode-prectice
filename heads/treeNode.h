#ifndef TREENODE_H
#define TREENODE_H
#include <iostream>
#include <queue>
using namespace std;

/* -------------------------------------------
 * 创建二叉树结构
 * -------------------------------------------*/
struct treeNode_2{
    int val;
    treeNode_2* left;
    treeNode_2* right;
    treeNode_2() : val(0), left(nullptr),right(nullptr) {} // 无参数传入的构造函数
};

/* -------------------------------------------
 * 创建三叉树结构
 * -------------------------------------------*/
struct treeNode_3{
    int val;
    treeNode_3* left;
    treeNode_3* right;
    treeNode_3* parent;
    treeNode_3() : val(0),parent(nullptr),left(nullptr),right(nullptr) {} // 无参数传入的构造函数
};


/* -------------------------------------------
 * 返回一维列表的广度优先搜索 A
 * -------------------------------------------*/
vector<int> treeBFS(treeNode_2* root) {
    // 创关键队列保存
    queue<treeNode_2 *> que;
    // 若不为空添加头结点进去
    if (root) que.push(root);
    vector<int> result;
    // 直到所有遍历完成
    while (!que.empty()) {
        // 这里记住pop次数 到这里的时候queue中包含的都是此深度的所有节点值
        int size = que.size();
        // 这里一定要使用固定大小size，不要使用que.size()，因为que.size是不断变化的
        for (int i = 0; i < size; i++) {
            treeNode_2 *node = que.front();
            que.pop();
            result.push_back(node->val);
            if (node->left) que.push(node->left);
            if (node->right) que.push(node->right);
        }
    }
    return result;
}

/* -------------------------------------------
 * 返回二维列表的层次搜索 bfs改编版 B
 * -------------------------------------------*/
vector<vector<int>> treeBFS_2d(treeNode_2* root) {
    // 创关键队列保存
    queue<treeNode_2*> que;
    // 若不为空添加进去
    if (root) que.push(root);
    vector<vector<int>> result;
    // 终止判断条件 只有所有都遍历完了才会结束循环
    while (!que.empty()) {
        // 这里记住pop次数 到这里的时候queue中包含的都是此深度的所有节点值
        int size = que.size();
        // 保存当前深度数值
        vector<int> vec;
        // 这里一定要使用固定大小size，不要使用que.size()，因为que.size是不断变化的
        for (int i = 0; i < size; i++) {
            treeNode_2* node = que.front();
            que.pop();
            vec.push_back(node->val);
            if (node->left) que.push(node->left);
            if (node->right) que.push(node->right);
        }
        result.push_back(vec);
    }
    return result;
}

/* -------------------------------------------
 * 使用DFS进行深度优先搜索 关键两点 C
 * 1、因为在便利过程中需要动态改变vector大小 且pushback之前需要创建好vector
 * 2、此处不需要返回result 通过引用直接对vector进行修改 添加返回值类型反而出错
 * -------------------------------------------*/
void treeDFS_2d(treeNode_2* root,vector<vector<int>>& result,int level) {
    if(!root) return ;
    // 1、首先要添加进去一个空的 要不找不到这块内存
    if (level >= result.size())
        result.push_back(vector<int>());

    result[level].push_back(root->val);

    // 2、直接调用
    treeDFS_2d(root->left,result,level+1);
    treeDFS_2d(root->right,result,level+1);
}

/* -------------------------------------------
 * 使用DFS进行深度优先搜索 强调的是深度 没有必要抢BFS的效果
 *
 * -------------------------------------------*/




#endif