# 对于：
```c++
const Stock & Stock::topval(Stock& s)const
{
    return  *s;
}
```
1 函数`返回值不会被修改`。

2 保证该方法`不会修改调用它的类对象`。(所以一般用于`内联`return value函数）一般

对于：

```c++
Stock & Stock::topval(const int s)
{
    return  *s;
}
```
保证传入的`变量不会在函数内部被修改`.这里指s地址不变


