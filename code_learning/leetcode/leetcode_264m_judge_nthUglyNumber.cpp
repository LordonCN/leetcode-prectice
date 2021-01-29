#include <iostream>
#include <vector>

/* -------------------------------------------
 * 质因数为235的正整数
 * 不考虑时间的话一个函数就好了
 * 学习质因数判断方法
 * 如果要判断第n个丑数那就在main写一个计数 从1 自增计数即可
 * 最快方法：查表
 * ------------------------------------------*/
using namespace std;

bool judge(int b)
{
    if(1 == b) return true;
    if(0 == b) return false;

    while(0 == b/3) b /= 3;
    while(0 == b/5) b /= 5;
    while(0 == b/2) b /= 2;

    if(0 == b)
        return true;
    else
        return false;
}


int main()
{
    int giveNumber;

//    return judge(giveNumber);

    return 0;
}