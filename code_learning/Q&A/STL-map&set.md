# 相同点
- 两者底层均由`红黑树`实现，且均为有序(红黑树是二叉平衡搜索树,但又有平衡属性).

- 插入数据保持唯一性，不能有重复 | **对于map可以使用数组方式进行索引替换**。

- 迭代器不会失效,但是不能用来修改键值

- map 与 set 的内部实现是二叉搜索平衡树 `红黑树`； 搜索效率是`logn`

# set

- 接口完全调用红黑树的方法;

- `不允许重复数值`的存在，也`不允许修改键值`;

# map [map常用函数](https://blog.csdn.net/sevenjoin/article/details/81943864)

- 默认情况下 map容器通过对键值对中`键的大小`来对所有`值`进行`升序排列`(对比hashmap插入后就乱了,跟桶排序有关，重要的是存储查找方便)。

- map是通过先构建pair(key,value),然后插入到红黑树中,其中key不能`重复`,且不能够修改(红黑树的要求),但是可以对value进行修改。

- 可选择无重复的键值对与有重复的键值对。

