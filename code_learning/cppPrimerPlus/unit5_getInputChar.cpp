#include <iostream>
// 从外部读取一段输入并显示出来 对比cin>> 与cin.get 两种输入方式
int main()
{
    using namespace std;
    int coutNumber = 0;
    char charInput;
    do 
    {
        cin.get(charInput);
        cout<<charInput;

    }while(cin.fail()==false); // use C+z+enter to stop


    
    return 0;
}