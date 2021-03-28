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
120 vector递归组合 `回溯`<br>
437 相互调用 耦合度高<br>
637 BFS求平均值 已经有一维 二维结果存储<br>
94 144 145 `递归`实现深度遍历 以及使用`栈`实现深度遍历

## 排序
56  stl-sort 二维数组<br>
75  双指针 vector-swap交换<br>
347 451 为stl-sort排序(hashmap+2dvector)<br>
215 快排 冒泡 stl-sort 数值大小排序<br>
179 stl-sort 数值逐位排序 按照字符串大小排序<br>
45  string-sort

## map-hash-set
45 用于保存同型异构题 first为排序后的结果 second为排序前<br>
347 字符统计 first为字母 second为出现次数<br>
451 字符统计 first为字母 second为出现次数<br>
17 查map表 排列组合 递归<br>
36 用来统计字符出现次数 map.clear()<br>
01 hashmap基本用法 常用操作<br>
03 hashmap配合deque实现统计个数 <br>
128 hashset基本用法 常用操作<br>
205 复杂度为n map索引 string替换<br>
242 复杂度为n map索引计数<br>
409 复杂度为n map统计<br>
697 两个hash组pair 分别统计位置与次数 进行判断<br>

## 递归
17 46 48 78排列组合递归 `回溯`<br>
22 递归创建括号 `回溯`<br>
39 vector递归组合 `回溯`<br>
120 递归 `动态`<br>
424 string递归 `遍历`<br>

递归创建树

## 贪心
53 依次遍历 寻找最优值 不考虑耗时<br>
135 <br>
466 <br>

## 动态规划
53 依次遍历 注重有效贡献<br>
413 等差数列满足状态转移方程 遍历比较即可<br>
198 与70 64相似 都是有将之前数值进行累计的思想 通过判断抢不抢来取max<br>
70 爬楼梯 经典题型 通过计算第n>2 层左右可能的爬楼方法 向上累加即可<br>
64 二维最小路径 明确状态转移方法为从`上`或者`左`最小值移动而来 取min<br>
516 序列类题目 通过二维数组存储 若无新回文字符串添加则取max当前最长回文 ```dp[i,j] = dp[i+1][j-1]+2 
or max(dp[i][j-1],dp[i+1][j])```<br>
300 序列类题目 外循环快于内循环 ```dp[i] = max(dp[t]+1,dp[i]) ```
91 一维dp 字符解码组合 较复杂<br>
542 二维dp 仅通过左上右下两次遍历即可完成计算距离最近点的距离<br>
62 二维路径搜索<br>
121 122 二维dp

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
  <br>TODO:`本质`是对从选择范围内的所有数值进行`两两比较`后排序
  <br>基本用法：
  可以结合以下仿函数进行使用
- less(小于)
- greater(大于)
- equal_to(等于)
- not_equal_to(不相等)
- less_equal(小于等于)
- greater_equal(大于等于)

```c++
    // 从小到大默认排序 可以用于数组 vector 给好起止就好
    sort(nums.begin(),nums.end());
    // 若要从大到小排序 需要配合下面的函数进行修改 同时也可以用于二维数组
    sort(nums.begin(),nums.end(),sortCmp);
    // lambda
    sort(nums.begin(),nums.end(),[](int a,int b){return a>b;});
    // 仿函数
    sort(nums.begin(),nums.end(),less<int>();
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
-  include `<vector>`
-  include `<algorithm>` 
```c++
    // 对于vector类型的数据reverse很好用
    // 对于顺序有比较高要求的情况来说很好用
    reverse(smallNumber.begin(),smallNumber.end());
    string s;
    reverse(s.begin(),s.end());
    
```

###### 7、accumulate-vector中元素求和的使用
- include `<numeric>`
- include `<vector>`

```c++
    vector<int>a;
    int aSum = accumulate(a.begin(),a.end(),0);
```


###### 8、erase-vector-map-set清空的使用
-  include `<vector>`
-  include `<unordered_map>`
-  include `<unordered_set>`
-  include `<set>`

```c++
    hashmap.erase(hashmap.begin(),hashmap.end());
    hashmap.erase(hashmap.find('A')); //实现精准擦除
    vector.erase(hashmap.begin(),hashmap.end());
    hashset.erase(hashmap.begin(),hashmap.end());
    
    // set初始化
    unordered_set<int> hashSet(nums.begin(),nums.end());
    set<int> Set(nums.begin(),nums.end());
```

###### 9、map-find查找 set-count计数
```c++
    if(hash.find(number) != hash.end()); // number存在
    if(set.count(number)); //number存在
```

##### 10、字符串截取 
```c++
    string sub = s.substr(s.begin(),length);
```

##### 11、数据查找 find 复杂度较高
```c++
    hash.find() != hash.end(); //找到后可直接进行操作 精准
    string.find() --> position/-1
```
##### 12、math 求幂运算
```c++
    pow(10,2) == 100
```

## 复习时间
- 1.24  114 108 树有关内容有点遗忘
- 1.25  整理链表 hashmap pair