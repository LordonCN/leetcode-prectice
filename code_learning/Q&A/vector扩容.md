# vector扩容问题

### STL 的 vector 底层实现是动态数组，大致原理就是：
vector 为空的时候没有预分配空间，每次添加一个元素时，
会判断当前(size)(`resize 直接进行扩容 短截长补0`)是否还有剩余可用空间，
如果没有则进行试探性扩容变为之前的2倍(capacity)(`reserve 改变扩容策略`)，
并且把内存拷贝到 新申请的内存空间上，并且释放原先的内存；

vector的数据安排以及操作方式，与array非常相似，两者的唯一差别在于空间的运用的灵活性。
vector是动态空间，随着元素的加入，它的内部机制会自行扩充空间以容纳新元素。
因此，vector的运用对内存的合理利用与运用的灵活性有很大的帮助。

### 譬如
`push_back` `insert` `resize` `pop` `erase`等均可以对vector进行扩容操作。以二倍方式扩容

[详情见](https://www.cnblogs.com/zzdbullet/p/10478744.html)

[win + linux 内存泄漏检测方法](https://www.cnblogs.com/skynet/archive/2011/02/20/1959162.html)
