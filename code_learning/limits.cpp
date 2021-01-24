#include <iostream>
#include <climits>
int main()
{
    using namespace std;
    // 四种类型数据的最大值
    int n_int = INT_MAX;
    unsigned short u_n_shot= SHRT_MAX+1;
    short n_shot = SHRT_MAX+1;
    long n_long = LONG_MAX;
    long long n_llong = LLONG_MAX;

    cout<<"int is"<< sizeof(int)<<"bytes."<<endl;
    cout<<"short is"<< sizeof(short)<<"bytes."<<endl;
    cout<<"long is"<< sizeof n_long <<"bytes."<<endl;
    cout<<"long long is"<< sizeof n_llong<<"bytes."<<endl;

    cout<<endl;
    cout<<"Maximum values:"<<endl;
    cout<<"int:"<<n_int<<endl;

    //若要显示1j进制
    // cout<<hex;
    //测试 无符号与有符号之间的关系
    cout<<"short:"<<n_shot<<endl;
    cout<<u_n_shot<<endl;

    int stop_for_awhile;
    cout<<"To stop the terminal close auto, add this to stop it";
    cin>>stop_for_awhile;
    return 0;
}