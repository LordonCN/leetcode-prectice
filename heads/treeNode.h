#ifndef TREENODE_H
#define TREENODE_H
#include <iostream>
#include <queue>
#include <stack>
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
 * DFS 非递归调用方法 与BFS实现方式有异曲同工
 * DFS 正常实现方式就是用递归即可
 * 3.28 复习
 * -------------------------------------------*/
vector<int> treeDFSStack(treeNode_2* root) {
    vector<int> result;
    if(!root) return result;

    stack<treeNode_2 *> sta;
    sta.push(root);
    // 直到所有遍历完成
    while (!sta.empty()) {
        // 这里记住pop次数 到这里的时候queue中包含的都是此深度的所有节点值
        treeNode_2 *node = sta.top();
        sta.pop();
        result.push_back(node->val);
        // 先push右 再push左 循环回来top就先取左 栈的机制 如果是队列的话就是先左再右 node取front
        if (node->right) sta.push(node->right);
        if (node->left) sta.push(node->left);
    }
    return result;
}
/* -------------------------------------------
 * 返回一维列表的广度优先搜索 A
 * 3.28 复习 4.15复习
 * -------------------------------------------*/
vector<int> treeBFS(treeNode_2* root) {
    // 创关键队列保存
    queue<treeNode_2 *> que;
    // 若不为空添加头结点进去
    if (root) que.push(root);
    vector<int> result;
    // 直到所有遍历完成
    while (!que.empty()) {
        treeNode_2 *node = que.front();
        que.pop();
        result.push_back(node->val);
        if (node->left) que.push(node->left);
        if (node->right) que.push(node->right);
    }
    return result;
}

/* -------------------------------------------
 * 返回二维列表的层次搜索 bfs改编版 B
 * 这里需要统计添加到vector中的长度
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
 * 使用递归二维数组进行层次遍历 关键两点:
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
 * 使用递归对树进行前序遍历很容易理解 但是面试过程中会要求使用非递归方法
 * 这里选择使用 迭代入栈 的方法进行操作
 * 4.15 复习
 * -------------------------------------------*/
void treeQianxu(treeNode_2* root,vector<int>&result)
{
    stack<treeNode_2*>sta;
    while(root || !sta.empty())
    {
        while(root)// 一直往左边走 到尽头 左侧为空那么就跳出循环拿中间root出栈
        {
            // 前序在这里保存数值 一遍历到就保存结果 跟递归一样
            result.push_back(root->val);
            sta.push(root);// 中间入
            root = root->left;// 切换到左边
        }
        root = sta.top();
        sta.pop();

        root = root->right;
    }

    return ;
}

// 4.15 复习
void treeZhongxu(treeNode_2* root,vector<int>&result)
{
    stack<treeNode_2*>sta;
    while(root || !sta.empty())
    {
        while(root)
        {
            sta.push(root);
            root = root->left;// 切换到左边
        }
        root = sta.top();
        sta.pop();
        // 中序在这里添加
        result.push_back(root->val);
        root = root->right;
    }

    return ;
}

// 后序遍历 先不看 一般不考
void treeHouxu(treeNode_2* root,vector<int>&result)
{
    stack<treeNode_2*>sta;
    treeNode_2* help = nullptr;
    while(root || !sta.empty())
    {
        while(root)// 一直往左边走 到尽头 左侧为空那么就跳出循环拿中间root出栈
        {
            sta.push(root);
            root = root->left;
        }
        root = sta.top();
        sta.pop();

        // 在中序遍历的基础上做出了调整
        if(!root->right || root->right == help)
        {
            result.push_back(root->val);
            help = root;
            root = nullptr;
        }
        else{
            sta.push(root);
            root = root->right;
        }

    }

    return ;
}

#endif