#include <iostream>
#include <string>
#include <cstring>

int main()
{
    using namespace std;
    char char_1[20];
    char char_2[] {"o"};
    string string_1;
    string string_2 = "s";

    cout<<strlen(char_2)<<endl;
    cout<<string_1.length()<<endl;
    cout<<"char_2 is:"<<char_2<<endl;
    cout<<"string_1 is:"<<string_1<<endl;
    
    // cout<<"the last one is:"<<char_1<<endl;
    // cout<<"the last one is:"<<char_2<<endl;
    // cin>>string_1;
    // cout<<"the last one is:"<<string_1<<endl;
    // cout<<"the last one is:"<<string_2<<endl;

    // 比较c语言字符串  与cpp之间的差别
    strcpy(char_1,char_2);
    string_1 = string_2;
    cout<<"char_1 is:"<<char_1<<endl;
    cout<<"string_1 is:"<<string_1<<endl;

    strcat(char_1,char_2);
    string_1 += string_2;
    cout<<"char_1 is:"<<char_1<<endl;
    cout<<"string_1 is:"<<string_1<<endl;

    cout<<strlen(char_1)<<endl;
    cout<<string_1.length()<<endl;
    cout<<"char_1 is:"<<char_1<<endl;
    cout<<"string_1 is:"<<string_1<<endl;
    cout<<string_1.size()<<endl;








    //结束停止语句
    int stop_for_awhile;
    cout<<"To stop the terminal close auto, add this to stop it";
    cin>>stop_for_awhile;

    return 0;
}