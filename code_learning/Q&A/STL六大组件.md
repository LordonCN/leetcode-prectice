# 六大组件 梳理

配置器 - 容器 - 迭代器 - 算法 - 仿函数 - 适配器

# 六大组件：
- Allocator(分配器)
- Container(容器) 各种基本数据结构   
  序列性 向量（vector）、双端队列（deque）、列表（list）
  
  关联性 集合（set）、多重集合（multiset）、映射（map）和多重映射（multimap）、树
- Iterator(迭代器) 连接containers和algorithms
- Algorithm(算法) 各种基本算法如sort、search…等
- Functor object(仿函数对象) ,重载`()`运算符,`[]`,`>`,`=`
  
为了把所有的东西整合起来，所以还需要一个：
- Adapter(适配器) 可改变containers、Iterators或Function object接口的一种组件

allocator给container分配数据存储空间，
algorithm通过iterator访问container内容，
functors协助algorithm完成不同任务(lambda),
dapter可以修饰functor。
