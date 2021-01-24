#include <iostream>
#include "treeNode.h"

using namespace std;
typedef treeNode_2 TreeNode;

/* -------------------------------------------
 * 递归创建树结构
 * -------------------------------------------*/
TreeNode* creatTree(TreeNode* &seed){
    char creat;
    // 类似于链表中new一个新节点s
    seed = new TreeNode;

    cout<<"creat left child?(Y/N)"<<endl;
    cin>>creat;
    if(creat == 'Y'){
        creatTree(seed->left);
    }
    else{
        seed->left = nullptr;
    }

    cout<<"creat right child?(Y/N)"<<endl;
    cin>>creat;
    if(creat == 'Y'){
        creatTree(seed->right);
    }
    else{
        seed->right= nullptr;
    }

    return seed;
}


int main()
{
    TreeNode* seedTree;
    creatTree(seedTree);

    return 0;
}