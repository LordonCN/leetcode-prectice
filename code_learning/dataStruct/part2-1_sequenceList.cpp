#include <iostream>
#include "listNode.h"
using namespace std; 

void listFunctionTest(dynamicSequenceList & dyList)
{
    
    dyList.element = new int[5];
    cout<<"list first place"<<dyList.element<<endl;
    *dyList.element = 5;
    // 通过自增进行索引
    dyList.element++;
    cout<<"list second place"<<dyList.element<<endl;
    *dyList.element = 15;
    // 通过数组进行索引
    dyList.element[4] = 9;

    cout<<"list test "<<dyList.element[4]<<endl;

}

bool initList(dynamicSequenceList &list)
{
    int maxNumber = 100;
    list.element  = new int[100]; // 此处跟agent那个抽象类初始化相似 之后就是对数组进行操作
    list.length = maxNumber;
    return true;
}
void fullListWithOneToHundered(dynamicSequenceList &list)
{
    for(int i =0;i<list.length;i++)
    {
    list.element[i] = i;
    }
}

int getListElement(dynamicSequenceList &list,int i)
{
    return list.element[i];
}

void ClientCode()
{
    dynamicSequenceList listForLearning;
    if(initList(listForLearning))
    {
        cout<<"The list has been inited"<<endl;
    }
    fullListWithOneToHundered(listForLearning);
    cout<<"After been update the data in List, we can see [38] the number in list is : "<<getListElement(listForLearning,38)<<endl;
}

int main()
{
    ClientCode();

    //stop for a while
    int stopForAwhile;
    cout<<endl;
    cout<<"To stop the terminal close auto, add this to stop it";
    cin>>stopForAwhile;

    
    return 0;


}