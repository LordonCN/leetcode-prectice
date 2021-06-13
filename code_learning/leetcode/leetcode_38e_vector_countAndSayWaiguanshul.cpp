#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

/* -------------------------------------------
 * ac 65 73
 * 循环依次修改 
 * ------------------------------------------*/

int main()
{
    int n = 4;
    string s = "1";
    // if(n == 1)return s;
    while(n-->1)
    {
        string temp = "";
        int l = 0,r = l;
        while(r<s.length()+1)
        {
            if(s[l] == s[r])r++;
            else
            {
                int len = r-l;
                temp += to_string(len);
                temp += s[l];
                l = r;
            }
        }
        s = temp;
    }
    // return s;
    return 0;
}