#include <iostream>
int main()
{
    using namespace std;
    cout.setf(ios_base::fixed, ios_base::floatfield);
    float tub = 10.0/3;
    double mint = 61.0/317.0;
    const float million = 1.0e-6;
    cout<<"tub"<<tub<<endl;
    //强制转换
    cout<<"tub_conv_to double is "<<(int)tub<<endl;
    cout<<"tub_conv_to double is "<<(long)tub<<endl;
    cout<<"tub_conv_to double is "<<(char)tub<<endl;
    cout<<"tub_conv_to double is "<<(double)tub<<endl;


    cout<<(int)16.666+(int)11.111<<"first one"<<endl;
    cout<<int (16.666)+int (11.111)<<"second one"<<endl;

    char ch = 'z';
    cout<<"number is:"<<int (ch)<<"and char is :"<<ch<<endl;
    
    cout<<"a million tub"<<million * tub<<endl;
    cout<<"nand ten million tubs"<<10*million*tub<<endl;
    
    cout<<"mint"<<mint;
    return 0; 
}