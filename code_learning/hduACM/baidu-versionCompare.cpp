#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <set>
using namespace std;

int main()
{
    string s1 = "1";
    string s2 = "1.1";

    vector<string>num1;
    string s = "";
    for(int i = 0;i<s1.length();i++)
    {
        if(s1[i]!='.')
        {
            s += s1[i];
        }
        else
        {
            num1.push_back(s);
            s = "";
        }
    }
    if(s!="")
        num1.push_back(s);

    vector<string>num2;
    s = "";
    for(int i = 0;i<s2.length();i++)
    {
        if(s2[i]!='.')
        {
            s += s2[i];
        }
        else
        {
            num2.push_back(s);
            s = "";
        }
    }
    if(s!="")
        num2.push_back(s);

    for(int i = 0;i<max(num1.size(),num2.size());i++)
    {
        if(num1[i]>num2[i])
        {
            cout<<1<<endl;
            return 1;
        }
        else if(num1[i]<num2[i])
        {
            cout<<-1<<endl;
            return -1;
        }
    }

    cout<<0<<endl;
    return 0;

}