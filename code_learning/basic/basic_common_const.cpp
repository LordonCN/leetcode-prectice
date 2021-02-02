#include <iostream>
#include <string>

using namespace std;


int main()
{
    // 定义常量指针 指向不可修改 地址所指向的数值可以修改
    int value_1 = 0;
    int*const intValuePtr_1= &value_1;
    *intValuePtr_1 = 10;
    cout<<intValuePtr_1<<" "<<value_1<<" "<<&value_1<<endl;


    // 定义整形常量
    const int cvalue = 10;


    // 定义常量数值指针
    int value_2 = 10;
    int value_22 = 11;
    const int* intValueptr_2  = &value_2;
    intValueptr_2 = &value_22;

    return 0;
}