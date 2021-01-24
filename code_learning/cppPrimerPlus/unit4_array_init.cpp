#include <iostream>
// 介绍数组的相关操作
// 一维数组 二维数组初始化方式


int main()
{
    using namespace std;
    short mounths[12] {};

    // 初始化为随机数
    int yams[2];
    cout<<"the first numb is:"<<yams[0]<<endl;
    cout<<"and next numb is:"<<yams[1]<<endl;

    char yams_char[10];
    cout<<"the first char is:"<<yams_char[6]<<endl;
    cout<<"and next char is:"<<yams_char[1]<<endl;


    yams[0] = 1;
    yams[1] = 10;
    yams[2] = 33;
    cout<<"the first is:"<<yams[0]<<endl;
    cout<<"and next is:"<<yams[1]<<endl;

    // 初始化为0
    int yams_1[2]= {};
    cout<<"the first is:"<<yams_1[0]<<endl;
    cout<<"and next is:"<<yams_1[1]<<endl;

    // 所以说必须要指明是哪一种类型 
    int yamcosts[3]={20,30,5};
    // 省略= 也可以
    int yamcosts_1[3] {20,30,5};
    cout<<"the last one is:"<<yamcosts[2]<<endl;

    // 方法1可以直接生成字符串
    char dong[6] {'a','s','d','d','0','\0'};
    char dog[] {'a','s',' ','d','\0','a','s','a','s',};
    cout<<dong<<endl;
    cout<<dog<<endl;
    // 方法2 这种方法定义最后会有一结束符
    char woshi_string[] = "hello";
    cout<<woshi_string<<endl;



    // 二维数组初始化 遍历最大到[3][4]
    int twoDimensArray[4][5]= {
        {1,2,3,4,5},
        {1,2,3,4,5},
        {1,2,3,4,5},
        {1,2,3,4,5}
    };












    int stop_for_awhile;
    char cin_test_char[20];

    cout<<"Input the char you want to ge";
    cin.getline(cin_test_char,20);
    cout<<cin_test_char<<" this is the char you input"<<endl;

    cout<<"To stop the terminal close auto, add this to stop it";
    cin>>stop_for_awhile;
    return 0;
}