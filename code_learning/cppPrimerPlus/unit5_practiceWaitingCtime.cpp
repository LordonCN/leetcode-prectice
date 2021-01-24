#include <iostream>
#include <ctime>

int main()
{
    using namespace std;
    float secs;
    cout<<"Please input how long it continue:"<<endl;
    cin >> secs;
    // 每秒计算时间
    clock_t delay = secs* CLOCKS_PER_SEC;

    // 记录开始时间
    clock_t start = clock();

    while (clock() - start < delay)
    {
        ;
    }
    cout<<"delay is over"<<endl;

    return 0;
} 