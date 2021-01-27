#ifndef TREENODE_H
#define TREENODE_H
#include <iostream>
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

#endif