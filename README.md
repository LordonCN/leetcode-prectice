#### 关键知识点

###### 0、多种类型数据结构的创建
- 链表
多用头插法创建 循环创建
```c++
ListNode* initList(ListNode* Head)
{
    Head->val = 0;
    Head->next = nullptr;
    ListNode *s;
    // 头插法进行链表填充
    for(int i = 2; i > 0; i--)
    {
        // 需要进行如下操作 否则报段错误
        s = new ListNode;
        s->val = i;
        // 开始插入
        s->next = Head->next;
        Head->next = s;
    }
    return Head;
}
```
- 树
<br> 使用递归创建
```c++
TreeNode* creatTree(TreeNode* &seed)
{
    char creat;
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

```

<br> 使用递归进行深度搜索 在有关平衡二叉树的判断上则需要对深度进行二次判断(单独计算左侧树最大深度，右侧树最大深度)

```c++
    int maxDepth(TreeNode* root) {
        if (root == NULL) return 0;
        return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }

    int minDepth(TreeNode* root) {
        if (root == NULL) return 0;
            {
                ldepth = minDepth(root->left),
                rdepth = minDepth(root->right);

                if(root->left && !root->right)
                    return 1+ldepth;
                
                if(!root->left && root->right)
                return 1+rdepth;

                return 1 + min(ledpth,rdepth);
            }

}
```
- 排序
<br>目前<br>
  347 451 为stl-sort排序(hashmap+2dvector)<br>
  251 为快排 冒泡 stl-sort排序

###### 1、const的使用
- 加载函数最后
```c++
    // the variable is constant and prevent to modifying it 
    // it's a way to replace the #define
    const int i = 5;

    // 声明常量成员函数 const在声明和定义中都要使用
    // 获取当前id 不做修改
    int  getId() const {return id;};

    // ※定义常量指针 地址不可修改 所指向的数值可以修改
    int value_1 = 0;
    int*const intValuePtr_1= &value_1;
    *intValuePtr_1 = 10;
    cout<<intValuePtr_1<<" "<<value_1<<" "<<&value_1<<endl;
    
    // ※定义常量数值指针 地址可修改 所指向的数值不可以修改
    int value_2 = 10;
    int value_22 = 11;
    const int* intValueptr_2  = &value_2;
    intValueptr_2 = &value_22;
    
    
```

###### 2、添加enum 内联 条件运算符进行状态切换
- enum
````c++
    state.h
        // 这里可以加当前是否允许攻击
        enum {attack,noattack};
        int state;
        void setAttackMode(){state = (state==attack)?noattack:attack};
````
    
###### 3、添加vactor容器(keyword:vector class)
- 创建容器
```c++
    Agents.h
        // 创建智能指针类型容器
        std::vector<std::shared_ptr<AgentAbstract>> all_agents;
        // 创建类指针容器
        std::vector<AgentAbstract*> ally;
        // 创建int容器
        std::vector<int> intCounter;
        vector<int*> intPointer;
        vector<string> stringList;
        vector<shared_ptr<int>> sharePtr;
        
```


###### 4、添加智能指针(keyword:smart ptr)
- 方法一： 类中声明，作用域在类全局 在构造函数中初始化
```` c++
game.h:
	std::shared_ptr<Agents> agents; // 先声明
	
game.cpp
        agents.reset(new Agents(policyChoice)); // TODO:智能指针声明后初始化

````
- 方法二：直接初始化完毕
```` c++
agents.cpp
        std::shared_ptr<DPPolicyAgent> DPPointer(new DPPolicyAgent);
````
- 测试程序
```` c++
#include <iostream>
#include <memory>

using namespace std;

/*************************************************************************
 *  int ptr 
 *======================================================================*/
void intFunctionTest(shared_ptr<int>(pointer) )
{
   *pointer = 10;
}

/*************************************************************************
 *  double ptr 
 *======================================================================*/
void doubleFunctionTest(shared_ptr<double>(pointer) )
{
    *pointer = 10.12;
}

/*************************************************************************
 *  return smart ptr
 *======================================================================*/
shared_ptr<int> intFunctionReturn(shared_ptr<int>(pointer))
{
   return pointer;
}

// 这一部分在game project中应用了 并且已更新在readme.md中
int main()
{
    // way1
    shared_ptr<int> pointerInt (new int);
    // way2
    shared_ptr<double> pointerDouble;
    pointerDouble.reset(new double);

    intFunctionTest(pointerInt);
    doubleFunctionTest(pointerDouble);

    cout<<"address of heaps is dynamic: "<<pointerInt<<endl;
    cout<<"address of stack is static: "<<&pointerInt<<endl;
    cout<<"value is: "<<*pointerInt<<endl;

    cout<<"address of heaps is dynamic: "<<pointerDouble<<endl;
    cout<<"address of stack is static: "<<&pointerDouble<<endl;
    cout<<"value is: "<<*pointerDouble<<endl;

    // 两个指针都指向同一块内容
    shared_ptr<int> pointerInt_r (new int);
    pointerInt_r = intFunctionReturn(pointerInt);

    cout<<"address of heaps is dynamic: "<<pointerInt_r<<endl;
    cout<<"address of stack is static: "<<&pointerInt_r<<endl;
    cout<<"value is: "<<*pointerInt_r<<endl;


    return 0;
}
````

###### 5、sort的使用
- 在 include <algorithm> 中
```c++
    // 从小到大默认排序 可以用于数组 vector 给好起止就好
    sort(nums.begin(),nums.end());

    // 若要从大到小排序 需要配合下面的函数进行修改 同时也可以用于二维数组
    sort(nums.begin(),nums.end(),sortCmp);

    bool sortCmp(const vector<int>&a,const vector<int>&b)
//    bool sortCmp(int a,int b)
     
    return a[0] < b[0]; // 升序 < 降序
//    return a < b; // 升序 < 降序
    }
```


###### 6、reverse的使用
- 在 include <algorithm> 中
```c++
    // 对于vector类型的数据reverse很好用
    // 对于顺序有比较高要求的情况来说很好用
    reverse(smallNumber.begin(),smallNumber.end());
```

### 复习时间
- 1.24  114 108 树有关内容有点遗忘