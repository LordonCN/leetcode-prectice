#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>

using namespace std;

/* -------------------------------------------
 * 思路：ac 5 50
 * 将所有string调整一下顺序 这里涉及到了引用操作
 * 使用迭代器对集合中元素进行索引并比较大小
 * ------------------------------------------*/
vector<vector<string>> groupAnagrams(vector<string>& strs) {
    vector<string>temp = strs;
    set<string>st;
    vector<vector<string>>result;
    
    for(auto &i : temp)
    {
        sort(i.begin(),i.end());
        st.insert(i);
    }
    set<string>::iterator ite;
    for( ite = st.begin();ite != st.end();ite++)
    {
        vector<string>store;
        for(int j = 0;j<temp.size();j++)
        {
            if(temp[j] == *ite)
                store.push_back(strs[j]);
        }
        result.push_back(store);
    }
    return result;
}

int main()
{
    vector<string>strs{"ab","abc","ba","cbd"};
    groupAnagrams(strs);
    return 0;
}