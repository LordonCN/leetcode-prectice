#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

/* -------------------------------------------
 * 使用求幂函数进行运算  ac 97 54
 * ------------------------------------------*/
vector<int> printNumbers(int  n)
{
    vector<int>result;
    for(int i = 1;i<pow(10,n);i++)
        result.push_back(i);
    return result;
}

int main()
{
    int n = 1;
    printNumbers(n);

    return 0;
}
