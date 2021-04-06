# 前驱与后缀的区别

```c++
// ++i 实现自增后返回该值 已经发生了改变
int & operator++()
{
    *this += 1;
    return this;
};

const int operator++(int) // 返回改变之前的值，实际结果已经发生了改变
{
    int res = *this;
    *this += 1;
    return res;
}

```

1 i++是由前者实现的
2 前者返回引用 后者返回const对象 且不能i++++操作
3 具体实现上区别为operator++() operator++(int) 用int作为两者的区分，没实际用途 