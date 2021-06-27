#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;

string reverseLeftWords(string s, int n) {
    if(n>s.length() || s == "")return s;
    string l = s.substr(0,n);
    string r = s.substr(n,s.length()-n);
    cout<<l<<" "<<r<<endl;
    return r+l;

}
int main()
{
    string s = "helloklsjdfl";

    reverseStringWords(s,10);

    return 0;
}