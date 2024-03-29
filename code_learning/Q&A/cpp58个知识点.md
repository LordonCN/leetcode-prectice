# 语言基础 (C/C++)

#### （0） 指针和引用的区别
* 指针是一个新的变量，指向另一个变量的地址，我们可以通过访问这个地址来修改另一个变量；而引用是一个别名，对引用的操作就是对变量的本身进行操作
* 指针可以有多级，引用只有一级
* 传参的时候，使用指针的话需要解引用才能对参数进行修改，而使用引用可以直接对参数进行修改
* 指针的大小一般是4个字节，引用的大小取决于被引用对象的大小
* 指针可以为空，引用不可以。

#### （1）在函数参数传递的时候，什么时候使用指针，什么时候使用引用？
* `需要返回函数内局部变量的内存的时候用指针`。使用指针传参需要开辟内存，用完要记得释放指针，不然会内存泄漏。而返回局部变量的引用是没有意义的
* 对栈空间大小比较敏感（比如递归）的时候使用引用。使用引用传递不需要创建临时变量，开销要更小
* 类对象作为参数传递的时候使用引用，这是C++类对象传递的标准方式
#### （2） 堆和栈有什么区别
* 从定义上：堆是由new和malloc开辟的一块内存，由程序员手动管理，栈是编译器自动管理的内存，存放函数的参数和局部变量。
* 堆空间因为会有频繁的分配释放操作，会产生内存碎片
* 堆的生长空间向上，地址越来越大 `比如测试的时候地址确实是一直在变大的`
* 栈的生长空间向下，地址越来越小
#### （3）堆快一点还是栈快一点？（字节提前批一面）
栈快一点。
因为操作系统会在底层对栈提供支持，会分配专门的寄存器存放栈的地址，栈的入栈出栈操作也十分简单，并且有专门的指令执行，所以栈的效率比较高也比较快。
而堆的操作是由C/C++函数库提供的，在分配堆内存的时候需要一定的算法寻找合适大小的内存。并且获取堆的内容需要两次访问，第一次访问指针，第二次根据指针保存的地址访问内存，因此堆比较慢。
#### （4） new和delete是如何实现的，new 与 malloc的异同处
在new一个对象的时候，首先会调用malloc为对象分配内存空间，然后调用对象的构造函数。delete会调用对象的析构函数，然后调用free回收内存。

new与malloc都会分配空间，但是new还会调用对象的构造函数进行初始化，malloc需要给定空间大小，而new只需要对象名
#### （5）既然有了malloc/free，C++中为什么还需要new/delete呢？
https://blog.csdn.net/leikun153/article/details/80612130

* malloc/free和new/delete都是用来申请内存和回收内存的。
* `在对非基本数据类型的对象使用的时候，对象创建的时候还需要执行构造函数`，销毁的时候要执行析构函数。而malloc/free是库函数，是已经编译的代码，所以不能把构造函数和析构函数的功能强加给malloc/free。
#### （6） C和C\+\+的区别
包括但不限于：
* C是面向过程的语言，C\+\+是面向对象的语言，C\+\+有“封装，继承和多态”的特性。封装隐藏了实现细节，使得代码模块化。继承通过子类继承父类的方法和属性，实现了代码重用。多态则是“一个接口，多个实现”，通过子类重写父类的虚函数，实现了接口重用。
* C和C\+\+内存管理的方法不一样，C使用malloc/free，C\+\+除此之外还用new/delete
* C\+\+中还有函数重载和引用等概念，C中没有
#### （7）delete和delete\[\]的区别

* delete只会调用一次析构函数，而delete\[\]会调用每个成员的析构函数

* 用new分配的内存用delete释放，用new\[\]分配的内存用delete\[\]释放

#### （8） C++、Java的联系与区别，包括语言特性、垃圾回收、应用场景等（java的垃圾回收机制）
包括但不限于：
* C\+\+ 和Java都是面向对象的语言，C\+\+是编译成可执行文件直接运行的，JAVA是编译之后在JAVA虚拟机上运行的，因此JAVA有良好的跨平台特性，但是执行效率没有C\+\+ 高。
* C\+\+的内存管理由程序员手动管理，JAVA的内存管理是由Java虚拟机完成的，它的垃圾回收使用的是标记-回收算法
* C\+\+有指针，Java没有指针，只有引用
* JAVA和C\+\+都有构造函数，但是C\+\+有析构函数但是Java没有
#### （9）C++和python的区别
包括但不限于：
1. python是一种脚本语言，是解释执行的，而C\+\+是编译语言，是需要编译后在特定平台运行的。python可以很方便的跨平台，但是效率没有C\+\+高。
2. python使用缩进来区分不同的代码块，C\+\+使用花括号来区分
3. C\+\+中需要事先定义变量的类型，而python不需要，python的基本数据类型只有数字，布尔值，字符串，列表，元组等等
4. python的库函数比C\+\+的多，调用起来很方便
## （10） Struct和class的区别
* 使用struct时，它的成员的访问权限默认是public的，而class的成员默认是private的
* struct的继承默认是public继承，而class的继承默认是private继承
* class可以用作模板，而struct不能
## （11） define 和const的联系与区别（编译阶段、安全性、内存占用等）
  联系：它们都是定义常量的一种方法。

  区别：
* define定义的常量没有类型，只是进行了简单的替换，可能会有多个拷贝，占用的内存空间大，const定义的常量是有类型的，存放在静态存储区，只有一个拷贝，占用的内存空间小。
* define定义的常量是在预处理阶段进行替换，而const在编译阶段确定它的值。
* define不会进行类型安全检查，而const会进行类型安全检查，安全性更高。
* const可以定义函数而define不可以。

## （12） 在C\+\+中const的用法（定义，用途）
* const修饰类的成员变量时，表示常量不能被修改
* const(在末尾)修饰类的成员函数，表示该函数不会修改类中的数据成员，不会调用其他非const的成员函数
* const(在开头)修饰类的成员函数，表示返回值要为const type不可修改

## （13） C++中的static用法和意义
static的意思是静态的，可以用来修饰变量，函数和类成员。
* 变量：被static修饰的变量就是静态变量，它会在程序运行过程中一直存在，会被放在静态存储区。局部静态变量的作用域在函数体中，全局静态变量的作用域在这个文件里。

* 函数：被static修饰的函数就是静态函数，静态函数只能在本文件中使用，不能被其他文件调用，也不会和其他文件中的同名函数冲突。

* 类：而在类中，被static修饰的成员变量是类静态成员，这个静态成员会被类的多个对象共用。被static修饰的成员函数也属于静态成员，不是属于某个对象的，
  `访问这个静态函数不需要引用对象名，而是通过引用类名来访问`。

`静态成员函数`是能直接调用`静态成员变量`的,但是静态成员函数不接受隐含的this自变量。所以，它就`无法访问自己类的非静态成员`。

局部静态变量在函数调用结束后也不会被回收，会一直在程序内存中，直到该函数再次被调用，它的值还是保持上一次调用结束后的值。

注意和const的区别。const强调值不能被修改，而static强调唯一的拷贝，对所有类的对象都共用。
#### （14） 计算下面几个类的大小：
```C++
class A {};
int main(){
  cout<<sizeof(A)<<endl;// 输出 1;
  A a; 
  cout<<sizeof(a)<<endl;// 输出 1;
  return 0;
}

```
空类的大小是1， 在C\+\+中空类会占一个字节，这是为了让对象的实例能够相互区别。具体来说，空类同样可以被实例化，并且每个实例在内存中都有独一无二的地址，因此，编译器会给空类隐含加上一个字节，这样空类实例化之后就会拥有独一无二的内存地址。当该空白类作为基类时，该类的大小就优化为0了，子类的大小就是子类本身的大小。这就是所谓的空白基类最优化。

空类的实例大小就是类的大小，所以sizeof(a)=1字节,如果a是指针，则sizeof(a)就是指针的大小，即4字节。
```C++
class A { virtual Fun(){} };
int main(){
  cout<<sizeof(A)<<endl;// 输出 4(32位机器)/8(64位机器);
  A a; 
  cout<<sizeof(a)<<endl;// 输出 4(32位机器)/8(64位机器);
  return 0;
}
```
因为有虚函数的类对象中都有一个虚函数表指针 __vptr，其大小是4字节<br>
```C++
class A { static int a; };
int main(){
  cout<<sizeof(A)<<endl;// 输出 1;
  A a; 
  cout<<sizeof(a)<<endl;// 输出 1;
  return 0;
}
```
静态成员存放在静态存储区，不占用类的大小, 普通函数也不占用类大小
```C++
class A { int a; };
int main(){
  cout<<sizeof(A)<<endl;// 输出 4;
  A a; 
  cout<<sizeof(a)<<endl;// 输出 4;
  return 0;
}
```
```C++
class A { static int a; int b; };;
int main(){
  cout<<sizeof(A)<<endl;// 输出 4;
  A a; 
  cout<<sizeof(a)<<endl;// 输出 4;
  return 0;
}
```
静态成员a不占用类的大小，所以类的大小就是b变量的大小 即4个字节
#### （15） C++的STL介绍（这个系列也很重要，建议侯捷老师的这方面的书籍与视频），其中包括内存管理allocator，函数，实现机理，多线程实现等
C++ STL从广义来讲包括了三类：算法，容器和迭代器。空间配置器、容器、迭代器、算法、仿函数、适配器
* 算法包括排序，复制等常用算法，以及不同容器特定的算法。
* 容器就是数据的存放形式，包括序列式容器和关联式容器，序列式容器就是list，vector等，关联式容器就是set，map等。
* 迭代器就是在不暴露容器内部结构的情况下对容器的遍历。

## （16） STL源码中的hash表的实现
STL中的hash表就unordered_map。使用的是哈希进行实现（注意与map的区别）。它记录的键是元素的哈希值，通过对比元素的哈希值来确定元素的值。

unordered_map的底层实现是hashtable，采用开链法（也就是用桶）来解决哈希冲突，当桶的大小超过8时，就自动转为红黑树进行组织。
## （17）解决哈希冲突的方式？
1. 线性探查。该元素的哈希值对应的桶不能存放元素时，循序往后一一查找，直到找到一个空桶为止，在查找时也一样，当哈希值对应位置上的元素与所要寻找的元素不同时，就往后一一查找，直到找到吻合的元素，或者空桶。
2. 二次探查。该元素的哈希值对应的桶不能存放元素时，就往后寻找1^2,2^2,3^2,4^2.....i^2个位置。
3. 双散列函数法。当第一个散列函数发生冲突的时候，使用第二个散列函数进行哈希，作为步长。
4. 开链法。在每一个桶中维护一个链表，由元素哈希值寻找到这个桶，然后将元素插入到对应的链表中，STL的hashtable就是采用这种实现方式。
5. 建立公共溢出区。当发生冲突时，将所有冲突的数据放在公共溢出区。
## （18） STL中unordered_map和map的区别
* unordered_map是使用哈希实现的，占用内存比较多，查询速度比较快，是常数时间复杂度。它内部是无序的，需要实现==操作符。
* map底层是采用红黑树实现的，插入删除查询时间复杂度都是O(log(n))，它的内部是有序的，因此需要实现比较操作符(<)。
## （19） STL中vector的实现
STL中的vector是封装了动态数组的顺序容器。不过与动态数组不同的是，vector可以根据需要自动扩大容器的大小。
具体策略是每次容量不够用时重新申请一块大小为原来容量两倍的内存，将原容器的元素拷贝至新容器，并`释放原空间`，返回新空间的指针。
清空一个vector可以通过赋值空vector的方法，也可以与空vector进行swap

在原来空间不够存储新值时，每次调用push_back方法都会重新分配新的空间以满足新数据的添加操作。如果在程序中频繁进行这种操作，还是比较消耗性能的。
#### （20） vector使用的注意点及其原因，频繁对vector调用push_back\(\)对性能的影响和原因。
如果需要频繁插入，最好先指定vector的大小，因为vector在容器大小不够用的时候会重新申请一块大小为原容器两倍的空间，并将原容器的元素拷贝到新容器中，并释放原空间，这个过程是十分耗时和耗内存的。频繁调用push_back()会使得程序花费很多时间在vector扩容上，会变得很慢。这种情况可以考虑使用list。

## （21）C++中vector和list的区别

vector和数组类似，拥有一段连续的内存空间。vector申请的是一段连续的内存，当插入新的元素内存不够时，通常以2倍重新申请更大的一块内存，将原来的元素拷贝过去，释放旧空间。因为内存空间是连续的，所以在进行插入和删除操作时，会造成内存块的拷贝，时间复杂度为o(n)。

list是由双向链表实现的，因此内存空间是不连续的。只能通过指针访问数据，所以list的随机存取非常没有效率，时间复杂度为o(n); 但由于链表的特点，能高效地进行插入和删除。

-----
vector拥有一段连续的内存空间，能很好的支持随机存取，因此vector::iterator支持“+”，“+=”，“<”等操作符。

list的内存空间可以是不连续，它不支持随机访问，因此list::iterator则不支持“+”、“+=”、“<”等

vector::iterator和list::iterator都重载了“\+\+”运算符。

总之，如果需要高效的随机存取，而不在乎插入和删除的效率，使用vector;

如果需要大量的插入和删除，而不关心随机存取，则应使用list。
#### （22） C++中的重载和重写的区别：
* 重载（overload）是指函数名相同，参数列表不同的函数实现方法。它们的返回值可以不同，但返回值不可以作为区分不同重载函数的标志。
* 重定义(redefine)是指函数名相同，参数列表相同，只有方法体不相同的实现方法。一般用于子类继承父类时对父类方法的重写。子类的同名方法屏蔽了父类方法的现象称为隐藏。
* 重写（overwrite）是指虚函数重写

详见：https://blog.csdn.net/weixin_30379911/article/details/99497160
## （23） C ++内存管理（热门问题）
https://blog.csdn.net/qq_43152052/article/details/98889139

在C\+\+中，内存分成5个区，他们分别是堆、栈、全局/静态存储区和常量存储区和代码区。
* 栈，在执行函数时，函数内局部变量的存储单元都可以在栈上创建，函数执行结束时这些存储单元自动被释放。栈内存分配运算内置于处理器的指令集中，效率很高，但是分配的内存容量有限。
* 堆，就是那些由new分配的内存块，他们的释放编译器不去管，由我们的应用程序去控制，一般一个new就要对应一个delete。如果程序员没有释放掉，那么在程序结束后，操作系统会自动回收。
* 全局/静态存储区，内存在`程序编译的时候`就已经分配好，这块内存在程序的整个运行期间都存在。它主要存放静态数据（局部static变量，全局static变量）、全局变量和常量。
* 常量存储区，这是一块比较特殊的存储区，他们里面存放的是常量字符串，不允许修改。
* 代码区，存放程序的二进制代码

关于这个有很多种说法，有的会增加一个自由存储区，存放malloc分配得到的内存，与堆相似。
## （24） 介绍面向对象的三大特性，并且举例说明每一个。
面向对象的三大特性是：封装，继承和多态。
* 封装隐藏了类的实现细节和成员数据，实现了代码模块化，
  如类里面的`private和public`；
* 继承使得子类可以复用父类的成员和方法，实现了代码重用；
* 多态则是“一个接口，多个实现”，通过父类调用子类的成员，实现了接口重用，如父类的指针指向子类的对象。

#### （25） 多态的实现（和下个问题一起回答）
C++ 多态包括编译时多态(静态多态)和运行时多态(动态多态).
编译时多态体现在函数重载和模板上，
运行时多态体现在虚函数上。

* 虚函数：在基类的函数前加上virtual关键字，在派生类中重写该函数，运行时将会根据对象的实际类型来调用相应的函数。如果对象类型是派生类，就调用派生类的函数；如果对象类型是基类，就调用基类的函数.
#### （26） C++虚函数相关（虚函数表，虚函数指针），虚函数的实现原理（热门，重要）
C++的虚函数是实现多态的机制,它是通过虚函数表实现的。
虚函数表是每个类中存放虚函数地址的指针数组（底层是哈希结构),
类的实例在调用函数时会在虚函数表中寻找函数地址进行调用，如果子类覆盖了父类的函数，则`子类的虚函数表`会指向子类实现的函数地址，否则指向父类的函数地址。

[TODO待定]一个类的所有实例都共享同一张虚函数表。

详见：[C++虚函数表剖析](https://blog.csdn.net/lihao21/article/details/50688337)

* 如果多重继承和多继承的话，子类的虚函数表长什么样子？
多重继承的情况下越是祖先的父类的虚函数更靠前，多继承的情况下越是靠近子类名称的类的虚函数在虚函数表中更靠前。详见：https://blog.csdn.net/qq_36359022/article/details/81870219

#### （27） 实现编译器处理虚函数表应该如何处理
编译器处理虚函数的方法是：
如果类中有虚函数，就将虚函数的地址记录在类的虚函数表中。派生类在继承基类的时候，如果有重写基类的虚函数，就将虚函数表中相应的函数指针设置为派生类的函数地址，否则指向基类的函数地址。
为每个类的实例添加一个虚表指针（vptr），虚表指针指向类的虚函数表。实例在调用虚函数的时候，通过这个虚函数表指针找到类中的虚函数表，找到相应的函数进行调用。
详见：[虚函数的作用及其底层实现机制](https://blog.csdn.net/iFuMI/article/details/51088091)
## （28） 基类的析构函数一般写成虚函数的原因
首先析构函数可以为虚函数，当析构一个指向子类的父类指针时，编译器可以根据虚函数表寻找到子类的析构函数进行调用，从而正确释放子类对象的资源。

如果析构函数不被声明成虚函数，则编译器实施`静态绑定`，在删除指向子类的父类指针时，
只会调用父类的析构函数而不调用子类析构函数，这样就会造成子类对象析构不完全造成`内存泄漏`。

## （29） 构造函数为什么一般不定义为虚函数
1）因为创建一个对象时需要确定对象的类型，而虚函数是在`运行时确定其类型`的。
而在构造一个对象时，**由于对象还未创建成功，编译器无法知道对象的实际类型**，是类本身还是类的派生类等等

2）虚函数的调用需要虚函数表指针，而该指针存放在对象的内存空间中；若构造函数声明为虚函数，那么由于对象还未创建，还没有内存空间，更没有虚函数表地址用来调用虚函数即构造函数了

#### （30） 构造函数或者析构函数中调用虚函数会怎样
在构造函数中调用虚函数，由于当前对象还没有构造完成，`此时调用的虚函数指向的是基类的函数实现方式`。

在析构函数中调用虚函数，`此时调用的是子类的函数实现方式`。
#### （31） 纯虚函数
纯虚函数是只有声明没有实现的虚函数，是对子类的约束，是接口继承

包含纯虚函数的类是抽象类，`它不能被实例化`，
`只有实现了这个纯虚函数的子类`才能生成对象,否则提示编译错误。

使用场景：当这个类本身产生一个实例没有意义的情况下，把这个类的函数实现为纯虚函数，比如动物可以派生出老虎兔子，但是实例化一个动物对象就没有意义。并且可以规定派生的子类必须重写某些函数的情况下可以写成纯虚函数。
#### （32） 静态绑定和动态绑定的介绍
[C++中的静态绑定和动态绑定](https://www.cnblogs.com/lizhenghn/p/3657717.html)

静态绑定也就是将该对象相关的属性或函数绑定为它的静态类型，也就是它在声明的类型，在编译的时候就确定。
在调用的时候编译器会寻找它声明的类型进行访问,`static实现`。

动态绑定就是将该对象相关的属性或函数绑定为它的动态类型，具体的属性或函数在运行期确定，通常通过`虚函数实现`动态绑定。

## （33） 深拷贝和浅拷贝的区别（举例说明深拷贝的安全性）
浅拷贝就是将对象的指针进行简单的复制，原对象和副本指向的是相同的资源。

而深拷贝是`新开辟一块空间`，将原对象的资源复制到新的空间中，并返回该空间的`地址`。

深拷贝可以避免重复释放和写冲突。例如使用浅拷贝的对象进行释放后，对原对象的释放会导致内存泄漏或程序崩溃。

#### （34） 对象复用的了解，零拷贝的了解
对象复用指得是设计模式，对象可以采用不同的设计模式达到复用的目的，最常见的就是继承和组合模式了。

零拷贝指的是在进行操作时，避免CPU从一处存储拷贝到另一处存储。
在Linux中，我们可以减少数据在内核空间和用户空间的来回拷贝实现，比如通过调用mmap()来代替read调用。
 
>用程序调用mmap()，磁盘上的数据会通过DMA被拷贝的内核缓冲区，接着操作系统会把这段内核缓冲区与应用程序共享，这样就不需要把内核缓冲区的内容往用户空间拷贝。应用程序再调用write(),操作系统直接将内核缓冲区的内容拷贝到socket缓冲区中，这一切都发生在内核态，最后，socket缓冲区再把数据发到网卡去。

## （35） 介绍C++所有的构造函数
C\+\+中的构造函数主要有三种类型：默认构造函数、重载构造函数和拷贝构造函数
* 默认构造函数是当类没有实现自己的构造函数时，编译器默认提供的一个构造函数。
* 重载构造函数也称为一般构造函数，一个类可以有多个重载构造函数，但是需要参数类型或个数不相同。可以在重载构造函数中自定义类的初始化方式。
* 拷贝构造函数是在发生对象复制的时候调用的,调用之处特别多，但使用move有时可以避免调用;

#### （36） 什么情况下会调用拷贝构造函数（三种情况）
* 对象以值传递的方式传入函数参数 
  >如 ` void func(Dog dog){};`
* 对象以值传递的方式从函数返回
  >如 ` Dog func(){ Dog d; return d;}`
* 对象需要通过另外一个对象进行初始化

详见：[C++拷贝构造函数详解](https://blog.csdn.net/lwbeyond/article/details/6202256)
#### （37） 结构体内存对齐方式和为什么要进行内存对齐？
因为结构体的成员可以有不同的数据类型，所占的大小也不一样。
同时，由于CPU读取数据是按块读取的，`内存对齐可以使得CPU一次就可以将所需的数据读进来`。

对齐规则：
* 第一个成员在与结构体变量偏移量为0的地址
* 其他成员变量要对齐到某个数字（对齐数）的整数倍的地址处。
* 对齐数=编译器默认的一个对齐数 与 该成员大小的较小值。
* linux 中默认为4
* vs 中的默认值为8
结构体总大小为最大对齐数的整数倍（每个成员变量除了第一个成员都有一个对齐数）

#### （38） 内存泄露的定义，如何检测与避免？
`动态分配内存`所开辟的空间，在`使用完毕后未手动释放`，导致一直占据该内存，即为内存泄漏。

造成内存泄漏的几种原因：

1）类的构造函数和析构函数中new和delete没有配套

2）在释放对象数组时没有使用delete[]，使用了delete

3）没有将基类的析构函数定义为虚函数，当基类指针指向子类对象时，如果基类的析构函数不是virtual，
那么子类的析构函数将不会被调用，子类的资源没有正确释放，因此造成内存泄露

4）没有正确的清楚嵌套的对象指针

避免方法：
1. malloc/free要配套
2. 使用智能指针；
3. 将基类的析构函数设为虚函数；

## （39） C++的智能指针有哪些
C++中的智能指针有auto_ptr,shared_ptr,weak_ptr和unique_ptr。
智能指针其实是将指针进行了封装，可以像普通指针一样进行使用，同时可以`自行进行释放`，避免忘记释放指针指向的内存地址造成内存泄漏。

* auto_ptr是较早版本的智能指针，在进行指针拷贝和赋值的时候，新指针直接接管旧指针的资源并且将旧指针指向空，但是这种方式在需要访问旧指针的时候，就会出现问题。归属权转移的问题。
* unique_ptr是auto_ptr的一个改良版，不能赋值也不能拷贝，保证一个对象同一时间只有一个智能指针。
* shared_ptr可以使得一个对象可以有多个智能指针，当这个对象所有的智能指针被销毁时就会自动进行回收。（内部使用计数机制进行维护）
* weak_ptr是为了协助shared_ptr而出现的。它不能访问对象，只能观测shared_ptr的引用计数，防止出现死锁。
#### （40） 调试程序的方法
* 通过设置断点进行调试
* 打印log进行调试
* 打印中间结果进行调试
#### （41） 遇到coredump要怎么调试
coredump是程序由于异常或者bug在运行时异常退出或者终止，
在一定的条件下生成的一个叫做core的文件，这个core文件会记录程序在运行时的内存，
寄存器状态，内存指针和函数堆栈信息等等。对这个文件进行分析可以定位到程序异常的时候对应的堆栈调用信息。

* 使用gdb命令对core文件进行调试

以下例子在Linux上编写一段代码并导致segment fault 并产生core文件
```
mkdir coredumpTest
vim coredumpTest.cpp
```
在编辑器内键入
```
#include<stdio.h>
int main(){
    int i;
    scanf("%d",i);//正确的应该是&i,这里使用i会导致segment fault
    printf("%d\n",i);
    return 0;
}
```
编译
```
g++ coredumpTest.cpp -g -o coredumpTest
```
运行
```
./coredumpTest
```
使用gdb调试coredump
```
gdb [可执行文件名] [core文件名]
```

#### （42） inline关键字说一下 和宏定义有什么区别
inline是内联的意思，可以定义比较小的函数。
因为函数频繁调用会占用很多的栈空间，比如在类中进行返回值与设置成员变量操作，进行入栈出栈操作也耗费计算资源，
所以可以`用inline关键字修饰频繁调用的小函数`。编译器会在`编译阶段`将代码体嵌入内联函数的调用语句块中。

1、内联函数在编译时展开，而宏在预编译时展开

2、在编译的时候，内联函数直接被嵌入到目标代码中去，而宏只是一个简单的文本替换。

3、内联函数可以进行诸如类型安全检查、语句是否正确等编译功能，宏不具有这样的功能。

4、宏不是函数，而inline是函数

5、宏在定义时要小心处理宏参数，一般用括号括起来，否则容易出现二义性。而内联函数不会出现二义性。

6、inline可以不展开，宏一定要展开。因为inline指示对编译器来说，只是一个建议，编译器可以选择忽略该建议，不对该函数进行展开。

7、宏定义在形式上类似于一个函数，但在使用它时，仅仅只是做预处理时符号表中的简单替换，因此它不能进行参数有效性的检测，也就不能享受C++编译器严格类型检查的好处，另外它的返回值也不能被强制转换为可转换的合适的类型，这样，它的使用就存在着一系列的隐患和局限性。
#### （43） 模板的用法与适用场景 实现原理
用template \<typename T\>关键字进行声明，接下来就可以进行模板函数和模板类的编写了

编译器会对函数模板进行两次编译：
在声明的地方对模板代码本身进行编译，这次编译只会进行一个语法检查，
并不会生成具体的代码。在运行时对代码进行参数替换后再进行编译，生成具体的函数代码。

## （44） 成员初始化列表的概念，为什么用成员初始化列表会快一些（性能优势）？TODO
!!!一个好的习惯是，按照成员定义的顺序进行初始化，因为成员是按照他们在类中出现的顺序进行初始化的，而不是按照他们在初始化列表出现的顺序初始化的.

成员初始化列表就是在类或者结构体的构造函数中，在参数列表后以冒号开头，逗号进行分隔的一系列初始化字段。如下：
```
class A{
int id;
string name;
FaceImage face;
A(int& inputID,string& inputName,FaceImage& inputFace):id(inputID),name(inputName),face(inputFace){} // 成员初始化列表
};
```
因为使用成员初始化列表进行初始化的话，会直接使用传入参数的拷贝构造函数进行初始化，
`省去了一次执行传入参数的默认构造函数的过程`(大华)，否则会调用一次传入参数的默认构造函数[得用一般构造函数来给成员变量赋值]。
所以使用成员初始化列表效率会高一些。<br>
另外，有三种情况是必须使用成员初始化列表进行初始化的：
* `常量成员`的初始化，因为常量成员只能初始化不能赋值
* 引用类型
* `没有默认构造函数的对象`必须使用成员初始化列表的方式进行初始化

详见[C++ 初始化列表](https://www.cnblogs.com/graphics/archive/2010/07/04/1770900.html)
#### （45） 用过C11吗，知道C11新特性吗？（有面试官建议熟悉C11）
简单来说 : auto lambda nullptr | smartptr 右值引用 初始化列表 原子操作

* 自动类型推导auto：auto的自动类型推导用于从初始化表达式中推断出变量的数据类型。通过auto的自动类型推导，可以大大简化我们的编程工作
* nullptr
：nullptr是为了解决原来C\+\+中NULL的二义性问题而引进的一种新的类型，因为NULL实际上代表的是0，而nullptr是void*类型的

* lambda表达式：它类似Javascript中的闭包，它可以用于创建并定义匿名的函数对象，以简化编程工作。Lambda的语法如下：
`[函数对象参数](操作符重载函数参数)mutable或exception声明->返回值类型{函数体}`
* thread类和mutex类
* 新的智能指针 unique_ptr和shared_ptr


* 更多详见：https://blog.csdn.net/caogenwangbaoqiang/article/details/79438279
#### （46） C++的调用惯例（简单一点C++函数调用的压栈过程）
函数的调用过程：

1）从栈空间分配存储空间

2）从实参的存储空间复制值到形参栈空间

3）进行运算

形参在函数未调用之前都是没有分配存储空间的，在函数调用结束之后，形参弹出栈空间，清除形参空间。

数组作为参数的函数调用方式是地址传递，形参和实参都指向相同的内存空间，调用完成后，形参指针被销毁，但是所指向的内存空间依然存在，不能也不会被销毁。

`当函数有多个返回值的时候`，不能用普通的 return 的方式实现，需要通过传回地址的形式进行，即地址/指针传递。可以存到vector中返回首地址进行索引。

## （47） C++的四种强制转换
四种强制类型转换操作符分别为：static_cast、dynamic_cast、const_cast、reinterpret_cast

* 1）static_cast ：
用于各种隐式转换。具体的说，就是用户各种基本数据类型之间的转换，比如把int换成char，float换成int等。
以及派生类（子类）的指针转换成基类（父类）指针的转换。
  >特性与要点：
    1. 它没有运行时类型检查，所以是有安全隐患的。
    2. 在派生类指针转换到基类指针时，是没有任何问题的，在基类指针转换到派生类指针的时候，会有安全问题,所以有了dynamiccast
    3. static_cast不能转换const，volatile等属性
* 2）dynamic_cast：
用于动态类型转换。具体的说，就是在基类指针到派生类指针，或者派生类到基类指针的转换。
dynamic_cast能够提供运行时类型检查，只用于含有虚函数的类。
dynamic_cast如果不能转换返回NULL。
* 3）const_cast：
用于去除const常量属性，使其可以修改 ，也就是说，原本定义为const的变量在定义后就不能进行修改的，但是使用const_cast操作之后，可以通过这个指针或变量进行修改; 另外还有volatile属性的转换。
* 4）reinterpret_cast
几乎什么都可以转，用在任意的指针之间的转换，引用之间的转换，指针和足够大的int型之间的转换，整数到指针的转换等。但是不够安全。
  
#### （48）string的底层实现
string继承自basic_string,其实是对char\*进行了封装，封装的string包含了char\*数组，容量，长度等等属性。

string可以进行动态扩展，在每次扩展的时候另外申请一块原空间大小两倍的空间（2^n），
然后将原字符串拷贝过去，并加上新增的内容。是不是类似于vector顺便将原来的部分释放掉。
## （49）一个函数或者可执行文件的生成过程或者编译过程是怎样的
预处理，编译，汇编，链接

* 预处理：对预处理命令进行替换等预处理操作
* 编译：代码优化和生成汇编代码
* 汇编：将汇编代码转化为机器语言
* 链接：将目标文件彼此链接起来

#### （50）set，map和vector的插入复杂度
set,map的插入复杂度就是红黑树的插入复杂度，是log(N)。

unordered_set,unordered_map的插入复杂度是常数，最坏是O(N).

vector的插入复杂度是O(N),最坏的情况下（从头插入）就要对所有其他元素进行移动，或者扩容重新拷贝
#### （51）定义和声明的区别
* 声明是告诉编译器变量的类型和名字，不会为变量分配空间,
  一般情况下头文件中只放变量的声明，因为头文件要被其他文件包含（即#include），如果把定义放到头文件的话，就不能避免多次定义变量

* 定义就是对这个变量和函数进行内存分配和初始化。需要分配空间，同一个变量可以被声明多次，但是只能被定义一次
  
TODO:基本类型变量的声明和定义（初始化）是同时产生的；而对于对象来说，声明和定义是分开的
```c++
A a; a = new A();
```
## （52）typdef和define区别(using)

define是预处理命令，在预处理是执行简单的替换，不做正确性的检查 `#define PII pair<int,int>`

typedef是在编译时处理的，它是在自己的作用域内给已经存在的类型一个别名 `typedef pair<int,int> PII;`

using 也能够实现这个功能 `using PII = pair<int,int>;`

#### （53）被free回收的内存是立即返还给操作系统吗？为什么
https://blog.csdn.net/YMY_mine/article/details/81180168

不是的，被free回收的内存会首先被ptmalloc使用双链表保存起来，当用户下一次申请内存的时候，会尝试从这些内存中寻找合适的返回。这样就避免了频繁的系统调用，占用过多的系统资源。同时ptmalloc也会尝试对小块内存进行合并，避免过多的内存碎片。

## （54）引用作为函数参数以及返回值的好处

对比值传递，引用传参的好处以及为什么以引用传递作为规范写法：

* 1）在函数内部可以对此参数进行修改,不想修改加const也方便.
* 2）提高函数调用和运行的效率,只需要传递地址即可（因为没有了传值和生成副本的时间和空间消耗）

用引用作为返回值最大的好处就是在内存中不产生被返回值的副本。

但是有以下的限制：

1）不能返回局部变量的引用。因为函数返回以后局部变量就会被销毁

2）不能返回函数内部new分配的内存的引用。虽然不存在局部变量的被动销毁问题，可对于这种情况（返回函数内部new分配内存的引用），又面临其它尴尬局面。例如，被函数返回的引用只是作为一 个临时变量出现，而没有被赋予一个实际的变量，那么这个引用所指向的空间（由new分配）就无法释放，造成memory leak

3）可以返回类成员的引用，但是最好是const。因为如果其他对象可以获得该属性的非常量的引用，那么对该属性的单纯赋值就会破坏业务规则的完整性。 
## （55）友元函数和友元类
https://www.cnblogs.com/zhuguanhao/p/6286145.html

友元提供了不同类的成员函数之间、类的成员函数和一般函数之间进行数据共享的机制。
通过友元，一个不同函数或者另一个类中的成员函数可以访问类中的私有成员和保护成员。
友元的正确使用`能提高程序的运行效率`，但同时也`破坏了类的封装性和数据的隐藏性`，导致程序可维护性变差。

1）友元函数

有元函数是`定义在类外的普通函数`不属于任何类，但可以访问其他类的私有成员。
是需要在类的定义中声明所有可以访问它的友元函数。

```
#include <iostream>

using namespace std;

class A
{
public:
    friend void set_show(int x, A &a);      //该函数是友元函数的声明
private:
    int data;
};

void set_show(int x, A &a)  //友元函数定义，为了访问类A中的成员
{
    a.data = x;
    cout << a.data << endl;
}
int main(void)
{
    class A a;

    set_show(1, a);

    return 0;
}
```

一个函数(类外定义)可以是多个类的友元函数，但是每个类中都要声明这个函数。

2）友元类

友元类的所有成员函数都是另一个类的友元函数，都可以访问另一个类中的隐藏信息（包括私有成员和保护成员）。        
但是另一个类里面也要相应的进行声明

 ```
 #include <iostream>

using namespace std;

class A
{
public:
    friend class C;                         //这是友元类的声明
private:
    int data;
};

class C             //友元类定义，为了访问类A中的成员
{
public:
    void set_show(int x, A &a) { a.data = x; cout<<a.data<<endl;}
};

int main(void)
{
    class A a;
    class C c;

    c.set_show(1, a);

    return 0;
}
 ```

使用友元类时注意： 

* (1) 友元关系不能被继承。 
* (2) 友元关系是单向的，不具有交换性。若类B是类A的友元，类A不一定是类B的友元，要看在类中是否有相应的声明。 
* (3) 友元关系不具有传递性。若类B是类A的友元，类C是B的友元，类C不一定是类A的友元，同样要看类中是否有相应的申明

#### （56） 说一下volatile关键字的作用
volatile的意思是“脆弱的”，表明它修饰的变量的值十分容易被改变，
所以编译器就不会对这个变量进行优化(CPU的优化是让该变量存放到CPU寄存器而不是内存),进而提供稳定的访问。
每次读取volatile的变量时，系统总是会从内存中读取这个变量，并且将它的值立刻保存。

## （57） STL中的sort()算法是用什么实现的，stable_sort()呢
STL中的
sort是用快速排序/堆排序和插入排序结合的方式实现的，不稳定 nlogn
stable_sort()是归并排序,归并是稳定的排序             nlogn -- nlog^2(n)

## （58）vector会迭代器失效吗？什么情况下会迭代器失效？
* 会
* 当vector在插入的时候，如果原来的空间不够，会将申请新的内存并将原来的元素移动到新的内存，此时指向原内存地址的迭代器就失效了，first和end迭代器都失效
* 当vector在插入的时候，end迭代器肯定会失效
* 当vector在删除的时候，被删除元素以及它后面的所有元素迭代器都失效。

怎样防止失效？在迭代器处进行操作的结果赋值给当前迭代器:
```c++
ite = nums.insert(ite, 0); // 插入一个新的值，并且指向它
ite = nums.erase(ite);// 删除当前值，指向下一个数值
```

#### （58）为什么C++没有实现垃圾回收？
* 首先，实现一个垃圾回收器会带来额外的空间和时间开销。
  你需要开辟一定的空间保存指针的引用计数和对他们进行标记mark。然后需要单独开辟一个线程在空闲的时候进行free操作。  
* 垃圾回收会使得C++不适合进行很多底层的操作。

# 死锁

#### （1） 死锁产生的必要条件（怎么检测死锁，解决死锁问题）
（1） 互斥：一个资源每次只能被一个进程使用。<br>
（2） 占有并请求：一个进程因请求资源而阻塞时，对已获得的资源保持不放。<br>
（3） 不可剥夺:进程已获得的资源，在末使用完之前，不能强行剥夺。<br>
（4） 循环等待:若干进程之间形成一种头尾相接的循环等待资源关系。<br>

产生死锁的原因主要是：<br>
（1） 因为系统资源不足。<br>
（2） 进程运行推进的顺序不合适。<br>
（3） 资源分配不当等。<br>
#### （2） 死锁的恢复
1. 重新启动：是最简单、最常用的死锁消除方法，但代价很大，因为在此之前所有进程已经完成的计算工作都将付之东流，不仅包括死锁的全部进程，也包括未参与死锁的全部进程。
2. 终止进程(process termination)：终止参与死锁的进程并回收它们所占资源。
   (1) 一次性全部终止；(2) 逐步终止(优先级，代价函数)
3. 剥夺资源(resource preemption):剥夺死锁进程所占有的全部或者部分资源。
   (1) 逐步剥夺：一次剥夺死锁进程所占有的一个或一组资源，如果死锁尚未解除再继续剥夺，直至死锁解除为止。
   (2) 一次剥夺：一次性地剥夺死锁进程所占有的全部资源。
4. 进程回退(rollback):让参与死锁的进程回退到以前没有发生死锁的某个点处，并由此点开始继续执行，希望进程交叉执行时不再发生死锁。但是系统开销很大：
   (1) 要实现“回退”，必须“记住”以前某一点处的现场，而现场随着进程推进而动态变化，需要花费大量时间和空间。
   (2) 一个回退的进程应当“挽回”它在回退点之间所造成的影响，如修改某一文件，给其它进程发送消息等，这些在实现时是难以做到的

# 细节：

#### （1） 不使用临时变量实现swap函数
* 使用异或/加减等方式，下面给出使用异或的实现方法
```C++
void swap(int& a,int& b){
  a=a^b;
  b=a^b;
  a=a^b;
}
```

#### （2） 快排存在的问题，如何优化
* 3 种快排基准选择方法：

随机（rand函数）、固定（队首、队尾）、三数取中（队首、队中和队尾的中间数）

* 4种优化方式：

优化1：当待排序序列的长度分割到一定大小后，使用插入排序 *

优化2：在一次分割结束后，可以把与Key相等的元素聚在一起，继续下次分割时，不用再对与key相等元素分割

优化3：优化递归操作

优化4：使用并行或多线程处理子序列 *

# 智力题
#### （1） 100层楼，只有2个鸡蛋，想要判断出那一层刚好让鸡蛋碎掉，给出策略（滴滴笔试中两个铁球跟这个是一类题）
* （给定了楼层数和鸡蛋数的情况）二分法+线性查找  从100/2=50楼扔起，如果破了就用另一个从0扔起直到破。如果没破就从50/2=25楼扔起，重复。
* 动态规划
#### （2） 毒药问题，1000瓶水，其中有一瓶可以无限稀释的毒药，要快速找出哪一瓶有毒，需要几只小白鼠
用二进制的思路解决问题。2的十次方是1024，使用十只小鼠喝一次即可。方法是先将每瓶水编号，同时10个小鼠分别表示二进制中的一个位。将每瓶水混合到水瓶编号中二进制为1的小鼠对应的水中。喝完后统计，将死亡小鼠对应的位置为1，没死的置为0，根据死亡小鼠的编号确定有毒的是哪瓶水，如0000001010表示10号水有毒。
#### （3） 赛马：有25匹马，每场比赛只能赛5匹，至少要赛多少场才能找到最快的3匹马？
* 第一次，分成5个赛道ABCDE，每个赛道5匹马，每个赛道比赛一场，每个赛道的第12345名记为 A1,A2,A3,A4,A5  B1,B2,B3,B4,B5等等，这一步要赛5场。
* 第二次，我们将每个赛道的前三名，共15匹。分成三组，然后每组进行比赛。这一步要赛3场。
* 第三次，我们取每组的前三名。共9匹，第一名赛道的马编号为1a,1b,1c，第二名赛道的马编号为2a,2b,2c，第三名赛道的马编号为3a,3b,3c。这时进行分析，1a表示第一名里面的第一名，绝对是所有马中的第一，所以不用再比了。2c表示第二名的三匹里头的最后一匹，3b和3c表示第三名里面的倒数两匹，不可能是所有马里面的前三名，所以也直接排除，剩下1b,1c,2a,2b,,3a，共5匹，再赛跑一次取第一第二名，加上刚筛选出来的1a就是所有马里面的最快3匹了。这一步要赛1场。
* 所以一共是5+3+1=9场。
#### （4） 先手必胜策略问题：100本书，每次能够拿1-5本，怎么拿能保证最后一次是你拿
寻找每个回合固定的拿取模式。最后一次是我拿，那么上个回合最少剩下6本。那么只要保持每个回合结束后都剩下6的倍数，并且在这个回合中我拿的和对方拿的加起来为6（这样这个回合结束后剩下的还是6的倍数），就必胜。关键是第一次我必须先手拿（100%6=4）本（这不算在第一回合里面）。
#### （5） 放n只蚂蚁在一条树枝上，蚂蚁与蚂蚁之间碰到就各自往反方向走，问总距离或者时间。
碰到就当没发生，继续走，相当于碰到的两个蚂蚁交换了一下身体。其实就是每个蚂蚁从当前位置一直走直到停止的总距离或者时间。
#### （6） 瓶子换饮料问题：1000瓶饮料，3个空瓶子能够换1瓶饮料，问最多能喝几瓶
拿走3瓶，换回1瓶，相当于减少2瓶。但是最后剩下4瓶的时候例外，这时只能换1瓶。所以我们计算1000减2能减多少次，直到剩下4.（1000-4=996，996/2=498）所以1000减2能减498次直到剩下4瓶，最后剩下的4瓶还可以换一瓶，所以总共是1000+498+1=1499瓶。
#### （7）在24小时里面时针分针秒针可以重合几次
24小时中时针走2圈，而分针走24圈，时针和分针重合24-2=22次，而只要时针和分针重合，秒针一定有机会重合，所以总共重合22次
#### （8） 有一个天平，九个砝码，一个轻一些，用天平至少几次能找到轻的？
至少2次：第一次，一边3个，哪边轻就在哪边，一样重就是剩余的3个；
第二次，一边1个，哪边轻就是哪个，一样重就是剩余的那个；
#### （9） 有十组砝码每组十个，每个砝码重10g，其中一组每个只有9g，有能显示克数的秤最少几次能找到轻的那一组砝码？
砝码分组1~10，第一组拿一个，第二组拿两个以此类推。。第十组拿十个放到秤上称出克数x，则y = 550 - x，第y组就是轻的那组
#### （10）生成随机数问题：给定生成1到5的随机数Rand5()，如何得到生成1到7的随机数函数Rand7()？
思路：由大的生成小的容易，比如由Rand7()生成Rand5()，所以我们先构造一个大于7的随机数生成函数。
记住下面这个式子：
```
RandNN= N( RandN()-1 ) + RandN() ;// 生成1到N^2之间的随机数
可以看作是在数轴上撒豆子。N是跨度/步长，是RandN()生成的数的范围长度，RandN()-1的目的是生成0到N-1的数，是跳数。后面+RandN()的目的是填满中间的空隙
```
比如` Rand25= 5( Rand5()-1 ) + Rand5()`可以生成1到25之间的随机数。我们可以只要1到21（3*7）之间的数字，所以可以这么写
```
int rand7(){
  int x=INT_MAX;
  while(x>21){
    x=5*(rand5()-1)+rand5();
  }
  return x%7+1;
}
```

#### （11） 烧 香/绳子/其他 确定时间问题：有两根不均匀的香，燃烧完都需要一个小时，问怎么确定15分钟的时长？
（说了求15分钟，没说开始的15分钟还是结束的15分钟，这里是可以求最后的15分钟）点燃一根A，同时点燃另一根B的两端，当另一根B烧完的时候就是半小时，这是再将A的另一端也点燃，从这时到A燃烧完就正好15分钟。

#### （12） 掰巧克力问题 N*M块巧克力，每次掰一块的一行或一列，掰成1*1的巧克力需要多少次？（1000个人参加辩论赛，1V1，输了就退出，需要安排多少场比赛）
每次拿起一块巧克力，掰一下（无论横着还是竖着）都会变成两块，因为所有的巧克力共有N\*M块，所以要掰N\*M-1次，-1是因为最开始的一块是不用算进去的。

每一场辩论赛参加两个人，消失一个人，所以可以看作是每一场辩论赛减少一个人，直到最后剩下1个人，所以是1000-1=999场。
