#include <iostream>
#include <memory>

using namespace std;

void intFunctionTest(shared_ptr<int>(pointer) )
{
   *pointer = 10;
}

void doubleFunctionTest(shared_ptr<double>(pointer) )
{
    *pointer = 10.12;
}

shared_ptr<int> intFunctionReturn(shared_ptr<int>(pointer))
{
   return pointer;
}

// 这一部分在game project中应用了 并且已更新在readme.md中
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