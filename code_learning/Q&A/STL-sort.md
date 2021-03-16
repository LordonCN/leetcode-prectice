# STL-Sort解读


#### STL中sort算法为什么选用插入排序+快排 而不用快排+其他呢？
STL中使用的sort为introsort,结合了`快排`/`堆排序`+`插入排序`的方法，其中快排与堆排序通过函数计算快排可拆分数的阈值，
当拆分段长度<16时采用递归。_RandomAccessIterator 类型数据是三点取中值的value取值方法重要体现


`选择排序`(Selection sort)，`插入排序`(Insertion Sort)，`冒泡排序`(Bubble Sort)。这三个排序是初学者必须知道的三个基本排序方式，且他们速度都不快 -- O(N^2)。 **选择排序**就不说了，最好情况复杂度也得O(N^2)，且还是个·不稳定·的排序算法，直接淘汰。

#### 冒泡排序和插入排序相比较呢？
首先，他们都是稳定的排序算法，且最好情况下都是O(N^2)。然而Bubble Sort在“几近排序但尚未完成”的情况下是没多少改进作用的，所以选择了`插入排序`与`快排`的组合。

#### 部分源码如下：

```c++

// 阈值判断选择执行方式
template<typename _RandomAccessIterator, typename _Size, typename _Compare>
void __introsort_loop(_RandomAccessIterator __first,
_RandomAccessIterator __last,
_Size __depth_limit,
_Compare __comp)
{
while (__last - __first > int(_S_threshold)) // 排序长度>16
{
if (__depth_limit == 0) // 不适用快排 可分割0层时改用堆排序
{
// 这里堆排序可以跳出循环  所以插入排序还要再判断一下长度
std::__partial_sort(__first, __last, __last, __comp);
return;
}
--__depth_limit;
// 快排 找到下一轮递归中值的位置
_RandomAccessIterator __cut = std::__unguarded_partition_pivot(__first, __last, __comp);
// 对右侧部分[cut,last]进行递归排序  退出来之后对左侧继续排序
std::__introsort_loop(__cut, __last, __depth_limit, __comp);
// 本循环中对左侧部分[first,cut]继续进行判断 长度小于16即采用插入排序
__last = __cut;
}
}

// sort source code 入口
template<typename _RandomAccessIterator, typename _Compare>
inline void __sort(_RandomAccessIterator __first, _RandomAccessIterator __last, _Compare __comp)
{
if (__first != __last)
{
// 包含快排与 恶劣情况下的堆排序
std::__introsort_loop(__first, __last,
std::__lg(__last - __first) * 2, //对排序分割恶化情况进行判断 __lg(__last - __first) * 2 最大快排拆分数
__comp);
// 插入排序 几近完成 的情况下使用  长度小于16的时候
std::__final_insertion_sort(__first, __last, __comp);
}
}
```




