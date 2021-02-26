#include <string>
#include <deque>


using namespace std;

/* -------------------------------------------
 * 改编227 无ac
 * 使用队列解决
 * 注意：
 * 解决' '问题
 * 解决加减乘除问题
 * 没解决大于10的整数运算
 * ------------------------------------------*/

int cal(string s_)
{
    int result = 0;
    deque<int>dq;
    deque<char>dq_char;
    string s;
    for(auto i : s_)
    {
        if(i != ' ')
            s += i;
    }
    for(int i = 0;i< s.size();i++)
    {
        if(s[i]-'0'>=0&&s[i]-'9'<=0)// 数字
        {
            dq.push_back(s[i]-'0');
            continue;
        }

        switch(s[i])
        {
            case '*':
            {
                int one = dq.back();
                dq.pop_back();
                int sec = s[i+1]-'0';
                dq.push_back(one*sec);
                i += 1;
                break;
            }

            case '/':
            {
                int one = dq.back();
                dq.pop_back();
                int sec = s[i+1]-'0';
                dq.push_back(one/sec);
                i += 1;
                break;
            }
            default:
                dq_char.push_back(s[i]);
        }
    }
    for(auto i : dq_char)
    {
        if(i == '+')
        {
            int b = dq.back();
            dq.pop_back();
            int a = dq.back();
            dq.pop_back();
            dq.push_back(a+b);
        }
        else
        {
            int b = dq.back();
            dq.pop_back();
            int a = dq.back();
            dq.pop_back();
            dq.push_back(a-b);
        }
    }
    return dq.back();
}

int main()
{
    string s = "3+5 / 2";


    cal(s);


    return 0;
}




