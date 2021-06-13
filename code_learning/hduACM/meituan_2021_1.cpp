#include <iostream>
#include <vector>
#include <algorithm>
#include <set>


using namespace std;

int main()
{
    int m,n;
    while(cin>>m>>n)
    {
        set<int> store;
        int t;
        for(int i=0;i<m;++i)
        {
            cin>>t;
            store.insert(t);
        }
        for(int i=0;i<n;++i)
        {
            cin>>t;
            store.insert(t);
        }
        set<int>::iterator it = store.begin();
        while(it!=store.end())
        {
            cout<<*it<<" ";
            ++it;
        }
        cout<<endl;
    }
    return 0;
}