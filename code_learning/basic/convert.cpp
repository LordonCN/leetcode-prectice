#include <iostream>
int stonetolb(int);
int main()
{
    using namespace std;
    int stone;
    cout<<"Enter the weight in stone:\n";
    cin >>stone;
    int pounds = stonetolb(stone);
    cout<<"stone="<<stone<<endl;
    cout<<"pounds=";
    cout<<pounds<<endl;
    cout<<"Ferdie weighs "<<stonetolb(16)<<"pound"<<endl;
    return 0;
}
int stonetolb(int sts)
{
    int result = sts*12;
    return result;
    
}