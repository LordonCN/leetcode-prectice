# 对于：
```c++
const Stock & Stock::topval(const Stock& s)const
{
    return  *s;
}
```
这样一个函数中

1 函数`返回值不会被修改`。

2 保证传入的`变量不会被修改`.

3 保证该方法`不会修改调用它的类对象`。(所以一般用于`内联`return value函数）

