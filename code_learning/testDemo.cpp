#include <iostream>
#include <vector>
#include "sort.h"
#include <queue>
using namespace std;

class A{
public:
    A(){};
    ~A(){};

};
struct Point
{
    int x, y; //点坐标
    int F, G, H; //F=G+H h为启发式函数
    Point *parent; // 用链表存储 方便回溯
    Point(int _x, int _y) :x(_x), y(_y), F(0), G(0), H(0), parent(NULL){}
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
    int arr[10]{6,7,8,2,3,4,9,10,1,5};
    priority_queue<int,int>;


    return 0;
}