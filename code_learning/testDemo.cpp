#include <iostream>
#include <vector>
#include "sort.h"

using namespace std;


class A{
public:
    A(){};
    ~A(){};

};

class B: public A{
private:
    static int a;
public:
    void getValue(){cout<<a<<endl;};
};

int B::a = 10;

int main()
{
    B b;
    const A &a = b;
    b.getValue();


    return 0;
}