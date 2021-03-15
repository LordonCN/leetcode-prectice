
string reverseStringWords(string s){
    // 准备工作
    if(s.length() == 0)return s;
    stack<char>store;
    bool canpush  = true;
    string result;
    // 存在一种情况 遍历到最后没有遇到空格 stack中内容没有释放出来
    for(int i = 0;i<s.size();i++)
    {
        if(s[i] != ' ' )//遇到字符了 且是第一个
            store.push(s[i]);
        else if(s[i] == ' ' && !store.empty())// 此单词结束了！
        {
            while(!store.empty())
            {
                result = store.top() + result ;
                store.pop();
            }
            result = ' ' + result ;// 先加上 最后返回的时候去掉就行了
        }
    }
    while(!store.empty())
    {
        result = store.top() + result ;
        store.pop();
    }
    if(result[0] != ' ')
        return result;
    else // 去掉首项
        return result.substr(1,result.length());
}