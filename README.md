# 关键知识点

###### 0、多种类型数据结构的创建
## 链表
02 链表按位相加 整体翻转 取map元素+链表尾插<br>
19 快慢指针 删除第n个点<br>
21 swap交换两链表 链表的拼接<br>
24 三个指针进行node两两交换<br>
61 整体翻转 使用map或者暴力破解<br>

## 树
17 排列组合<br>
46 排列组合<br>
48 排列组合<br>
78 排列组合<br>
22 递归创建括号 `回溯`<br>
39 vector递归组合 `回溯`<br>

## 排序
56  stl-sort 二维数组<br>
75  双指针 vector-swap交换<br>
347 451 为stl-sort排序(hashmap+2dvector)<br>
215 stl-sort 数值大小排序<br>
179 stl-sort 数值逐位排序 按照字符串大小排序<br>
251 快排 冒泡 stl-sort排序<br>
45  string-sort

## map-hash
45 用于保存同型异构题 first为排序后的结果 second为排序前<br>
347 字符统计 first为字母 second为出现次数<br>
451 字符统计 first为字母 second为出现次数<br>
17 查map表 排列组合 递归<br>
36 用来统计字符出现次数 map.clear()

## 递归
17 46 48 78排列组合递归<br>
22 递归创建括号 `回溯`<br>
39 vector递归组合<br>
递归创建树

## 贪心
53 依次遍历 寻找最优值 不考虑耗时

## 动态规划
53 依次遍历 注重有效贡献

## cpp 相关知识点
###### 1、const的使用
```c++
    // 引用只是为提高程序执行效率
    // 函数中首先选择引用传递 & 直接对传入参数进行修改
    void sortVector(vector<int>&nums)
    { quickSort(nums);}

    // 如果不想在原来基础上进行修改 加个const即可 
    vector<int> sortVector(const vector<int>&nums)
    {
        vector<int>fakenums = nums;
        quickSort(fakenums);
        return fakenums;
    }
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

###### 2、添加enum 条件运算符进行状态切换
- enum
````c++
    state.h
        // 这里可以加当前是否允许攻击
        enum {attack,noattack};
        int state;
        void setAttackMode(){state = (state==attack)?noattack:attack};
````
    
###### 3、添加vactor容器
- 创建容器
```c++
    Agents.h
        // 创建智能指针类型容器
        vector<std::shared_ptr<AgentAbstract>> all_agents;
        vector<shared_ptr<int>> sharePtr;
        
        // 创建类指针容器
        vector<AgentAbstract*> ally;
        
        // 创建int容器
        std::vector<int> intCounter;
        vector<int*> intPointer;
        vector<string> stringList;
        
```


###### 4、添加智能指针(keyword:smart ptr)
- 方法一： 类中声明，作用域在类全局 在构造函数中初始化
```` c++
game.h:
	std::shared_ptr<Agents> agents; // 先声明
	
game.cpp
    agents.reset(new Agents(policyChoice)); // 智能指针声明后初始化

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

/**************************************
 *  int ptr 
 *====================================*/
void intFunctionTest(shared_ptr<int>(pointer) )
{
   *pointer = 10;
}

/**************************************
 *  double ptr 
 *====================================*/
void doubleFunctionTest(shared_ptr<double>(pointer) )
{
    *pointer = 10.12;
}

/**************************************
 *  return smart ptr
 *====================================*/
shared_ptr<int> intFunctionReturn(shared_ptr<int>(pointer))
{
   return pointer;
}

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

###### 5、stl-sort的使用(不能在原数组调整)
- 在 include <algorithm> 中
<br>`本质`是对从选择范围内的所有数值进行`两两比较`后排序
<br>基本用法：
  
```c++
    // 从小到大默认排序 可以用于数组 vector 给好起止就好
    sort(nums.begin(),nums.end());
    // 若要从大到小排序 需要配合下面的函数进行修改 同时也可以用于二维数组
    sort(nums.begin(),nums.end(),sortCmp);
    
    // lambda
    sort(nums.begin(),nums.end(),[](int a,int b){return a>b});
```
<br>当前适用情况：
```c++
    // 二维数组按照其中某一维度排序 56
    bool sortCmp(const vector<int>&a,const vector<int>&b)
    {
        return a[0] < b[0]; // 升序 < 降序
    }
    // 数值大小排序 215
    bool sortCmp(int a,int b)
    {
        return a < b; // 升序 < 降序
    }
    // 按照字符串大小排序
    // 数值逐位排序 179
    bool sortCmp(int a,int b)
    {
        return to_string(a) < to_string(b); 
    }
```

###### 6、reverse-vector内容翻转的使用
- 在 include <algorithm> 中
```c++
    // 对于vector类型的数据reverse很好用
    // 对于顺序有比较高要求的情况来说很好用
    reverse(smallNumber.begin(),smallNumber.end());
```

###### 7、accumulate-vector中元素求和的使用
- include <numeric>

```c++
    int aSum = accumulate(a.begin(),a.end(),0);
```


###### 8、erase-vector-map-set清空的使用
- 清空
```c++
    hashmap.erase(hashmap.begin(),hashmap.end());
    vector.erase(hashmap.begin(),hashmap.end());
    set.erase(hashmap.begin(),hashmap.end());
```



## 复习时间
- 1.24  114 108 树有关内容有点遗忘
- 1.25  整理链表 hashmap pair