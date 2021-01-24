#include <iostream>
#include <vector>
#include <string>
#include <memory>

using namespace std;

int main()
{
    vector<int> intValue;
    intValue.push_back(3);
    intValue.push_back(88);
    intValue.push_back(323);
    cout<<intValue.size()<<endl;
    cout<<intValue.empty()<<endl;
    cout<<intValue.front()<<endl;
    cout<<intValue.back()<<endl;

    cout<<"after clear and shrink"<<endl;
    intValue.clear();
    intValue.shrink_to_fit();
    intValue.push_back(88);

    cout<<intValue.size()<<endl;
    cout<<intValue.empty()<<endl;
    cout<<intValue.front()<<endl;
    cout<<intValue.back()<<endl;

//    intValue.

    // additional operate all of things it can include
    vector<int*> intPointer;
    vector<string> stringList;
    vector<shared_ptr<int>> sharePtr;

    // and so on

    return 0;
}