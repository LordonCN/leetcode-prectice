#include <iostream>
using namespace std;

int main()
{
    char charr = 'A';
    int number = charr;
    cout<<"char"<<charr<<"and its number is"<<number<<endl;

    char charr_2 = charr+1;
    int number_2 = charr_2;
    cout<<"char2"<<charr_2<<"and its number is"<<number_2<<endl;

    
    //cout.put只能打印字符串  
    cout.put('i')<<endl;
    cout.put(int('i'));
    cout.put(33);


    int stop_for_awhile;
    cout<<"To stop the terminal close auto, add this to stop it";
    cin>>stop_for_awhile;

    return 0;
}