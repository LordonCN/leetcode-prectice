#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

/* -------------------------------------------
 * 注意: ac 100 40
 * ------------------------------------------*/
vector<string> restoreIpAddresses(string s) {
    vector<string>result;
    string temp;
    DFS(result,s,temp,0);
    return result;
}
// 条件判断 是否满足
bool isOK(string s)
{
    if(s.size()>1 && s[0] == '0')return false;// .010.
    if(s.size()>3)return false; // .1111.
    else if(s.size() == 3)
    {
        if(s>"255")return false;// .324.
    }
    return true;
}
void DFS(vector<string>&result,const string s,string temp,int p)
{
    string judge;
    // stop case && add last string
    if((temp.size()-3) == p)
    {
        string tial = s.substr(p,s.size()-p);
        if(!isOK(tial))return;
        temp += tial;
        if(temp.back() == '.')return;
        result.push_back(temp);
        return;
    }
    
    for(int i = p;i<s.size();i++)
    {
        // 中间部分需要加辅助字符串进行条件判断
        judge += s[i];
        if(!isOK(judge))return;
        DFS(result,s,temp+judge+'.',i+1);
    }
    return;
}

int main()
{
    string s = "210207";
    restoreIpAddresses(s);
    return 0;
}