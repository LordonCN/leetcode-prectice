#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n= 0;
    // 一共n个罐 最多吃k个
    cin>>n;
    vector<vector<char>>matrix(n,vector<char>(n,0));
    for(int i = 0;i<n;i++)
        cin>>matrix[i][0]>>matrix[i][1]>>matrix[i][2]>>matrix[i][3];

    int m_end = matrix.size()-1;
    int n_end = matrix[0].size()-1;
    int m_begin = 0, n_begin = 0;
    vector<char> ans;
    while (m_begin < m_end && n_begin < n_end) {
        int i = m_begin;
        int j = n_begin;
        for ( ; j < n_end; ++j) {
            ans.push_back(matrix[i][j]);
        }
        for ( ; i < m_end; ++i) {
            ans.push_back(matrix[i][j]);
        }
        for ( ; j > n_begin; --j) {
            ans.push_back(matrix[i][j]);
        }
        for ( ; i > m_begin; --i) {
            ans.push_back(matrix[i][j]);
        }
        // 每一圈之后，行列向内缩减1
        --m_end;
        --n_end;
        ++m_begin;
        ++n_begin;
    }
    // 由于for循环访问头部元素，不访问尾部元素，最后可能剩一行或者一列
    if (m_begin == m_end) {
        for (int i = n_begin; i <= n_end; ++i) {
            ans.push_back(matrix[m_begin][i]);
        }
    } else if (n_begin == n_end) {
        for (int i = m_begin; i <= m_end; ++i) {
            ans.push_back(matrix[i][n_begin]);
        }
    }
    string s;
    for(int i = 0;i<ans.size();i++)
    {
        if(ans[i]!='0')s += ans[i];
    }

    cout<<s<<endl;
    return 0;

}