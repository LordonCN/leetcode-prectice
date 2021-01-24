#include <iostream>
#include <string>

using namespace std;

int main()
{
    basic_string<char> stringBase1;
    stringBase1 += 'h';
    stringBase1 += 'h';

    // 目前常用的三种形式
    string stringOne = "hello";
    string stringTwo("the second one");
    string stringThird;
    stringThird += "hello";

    // 四种查找方式
    stringOne.find('d');
    stringOne.find("skdjfk");

    stringOne.find_first_not_of('a');
    stringOne.find_first_of('a');

    stringTwo.append(" ksjfkskfs");

//    stringOne.


    cout<<stringBase1<<endl;

    cout<<stringTwo<<endl;

    return 0;
}