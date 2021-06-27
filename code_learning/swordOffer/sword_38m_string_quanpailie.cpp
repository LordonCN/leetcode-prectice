
// 这种全排列的题目确实不熟练
// 是不是都是递归交换完成的？
class Solution {
public:
    vector<string> permutation(string s) {
        set<string>store;// 防止重复
        vector<string>out;// 存储最后结果
        if(s == "")return out;// corner case

        helper(s,store,0);

        for(auto ite : store)
            out.push_back(ite);
        return out;
    }

    void helper(string s,set<string>&store,int idx)
    {
        if(idx > s.length()-1)// 递归结束标志 索引大于字符总长度
        {
            store.insert(s);
            return ;
        }
        for(int i = idx;i<s.length();i++)
        {
            swap(s[i],s[idx]);
            helper(s,store,idx+1);
            swap(s[i],s[idx]);
        }
        return ;
    }
};