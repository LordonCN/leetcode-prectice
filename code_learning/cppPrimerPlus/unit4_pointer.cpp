#include <iostream>
#include <string>
#include <cstring>

#include <vector>
#include <array>


struct Student  //声明结构体类型Student
{
   std::string name;
   int num;
   char sex;
};


// 初始化类结构
Student student1,student3,student4;
int main()
{
    student1.name = "dong";


    using namespace std;
    // 普通指针类型
    int updates = 6;
        // 意思是说我这个pointerUpdates指针变量就是int*类型的 所以直接赋值或者另起一行都是给地址才行
    int* pointerUpdates;
    pointerUpdates = &updates;
    int* pointerUpdatesTest = &updates;
    cout<<"values is:"<<updates<<endl;
    cout<<"values is:"<<*pointerUpdates<<endl;
    cout<<"values is:"<<*pointerUpdatesTest<<endl;
    cout<<"values address is :"<<&updates<<endl;
    cout<<"values address is :"<<pointerUpdates<<endl;




    // 动态数组
    double* dynamicMatrixPointer = new double[10];
        //指针赋值数组方法
    dynamicMatrixPointer[0] = 1.1;
    dynamicMatrixPointer[1] = 1.2;
    dynamicMatrixPointer[2] = 0.0;
    dynamicMatrixPointer[3] = 1.3;
    cout<<"dynamicMatrix 0:"<<dynamicMatrixPointer[0]<<endl;
        //指针赋值地址方法
    *dynamicMatrixPointer = 2;
    cout<<"dynamicMatrix 0:"<<dynamicMatrixPointer[0]<<endl;
    cout<<"dynamicMatrix 1:"<<dynamicMatrixPointer[1]<<endl;
    *(dynamicMatrixPointer+1) = 2;
    cout<<"dynamicMatrix 1:"<<dynamicMatrixPointer[0]<<endl;
    cout<<"dynamicMatrix 2:"<<dynamicMatrixPointer[2]<<endl;
        // 改变了指针起始位置 指针没问题 数组有问题
    dynamicMatrixPointer = dynamicMatrixPointer+1;
    cout<<"dynamicMatrix 0:"<<dynamicMatrixPointer[0]<<endl;
    cout<<"dynamicMatrix 1:"<<dynamicMatrixPointer[1]<<endl;
    cout<<"dynamicMatrix 2:"<<dynamicMatrixPointer[2]<<endl;


    // 指针数组另外测试
        //指针加1改变类型为本身类型的长度 int地址加了4 double加了8
    int arrayPointerInt[10];
    double arrayPointerDouble[19];
    double* pointerArrayDouble = arrayPointerDouble;
    int* pointerArrayInt= &arrayPointerInt[0];
    cout<<"pointerArrayInt test :"<<pointerArrayInt<<endl;
    cout<<"pointerArrayDouble test :"<<pointerArrayDouble<<endl;
    pointerArrayInt= pointerArrayInt+1;
    pointerArrayDouble= pointerArrayDouble+1;
    cout<<"pointerArrayInt after +1 test :"<<pointerArrayInt<<endl;
    cout<<"pointerArrayDouble after +1 test :"<<pointerArrayDouble<<endl;
    

    //*****************************************************************
    // string指针的使用方式 
        // new通过在运行过程中申请内存 返回存储地址给指针
    string* cat2 = new string;
    *cat2 = "helloo";
    string cat ="akda"; 
    string* catPointer;
    catPointer = &cat;
    delete cat2;

    
    // char指针的使用方式
    char* tiger = new char[20+1];
    tiger = "tigere1";
    char* bear= "iiibear";
    const char* bird = "wkjlsdf";
    cout<<cat<<"  next is catpointer: " <<catPointer<< endl;
    cout<<bird<<"  next is bear: " <<&bear<<"   "<<(int*) bear<< endl;
    delete tiger;


    // int指针的两种使用方式
    int* turtlePointerNew = new int ; //先开辟存储地址
    *turtlePointerNew = 6;  // 赋值
    int turtle = 6;
    int* turtlePointer = &turtle; //直接指向变量地址
    cout<<"pointer test get address and value"<<*turtlePointerNew<<endl;
    delete turtlePointerNew;
    

    // 结构体类型的指针
    Student* stuPointer;  //定义指向结构体类型Student的数据的指针变量
    Student* stuPoint = new Student;
    stuPointer=new Student;  //用new运算符开辟一个存放Student型数据的空间

    stuPointer->name="Wang Fun";  //向结构体变量的成员赋值
    stuPointer->num=10123;
    stuPointer->sex='m';
    cout<<"struct pointer address is :"<<stuPointer<<endl;
    cout<<"struct pointer name is :"<<stuPointer->name<<endl;
    delete stuPointer;



    //vector array practice:
    // 两者都是模板类 但是vector效率略低 array效率与数组相同 但是 更方便更安全 
    // 不同点：array 与 数组的存储地址相同 vector存储在自由存储区或者堆栈  
    double preArray[2] = {1.1,2.2};

    //TODO能打印 能执行 释放的时候出问题 本质还是 new delete
    vector<double> vectorDoubleTest(2); //创建vector 含有两个元素
    vectorDoubleTest[1] = 1.1;
    vectorDoubleTest[2] = 5.1;
    cout<<"vector test"<<vectorDoubleTest[1]<<endl;

    array<double,2> arrayDoubleTest = {1.1,2.2};
    cout<<"array test"<<arrayDoubleTest[1]<<endl;
    







    //stop for a while
    int stopForAwhile;
    cout<<endl;
    cout<<"To stop the terminal close auto, add this to stop it";
    cin>>stopForAwhile;

    return 0;
}