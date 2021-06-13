#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void process(int a,int b)
{
    vector<int>nums;
    for(int i = 0;i<a;i++)
    {
        int anumb;
        cin>>anumb;
        nums.push_back(anumb);
    }

    vector<int>numsb;
    for(int i = 0;i<b;i++)
    {
        int anumb;
        cin>>anumb;
        numsb.push_back(anumb);
    }
    vector<int>result;
    merge(nums.begin(),nums.end(),numsb.begin(),numsb.end(), std::back_inserter(result));
    sort(result.begin(),result.end());

    for(int i = 0;i<result.size();i++)
    {
        if(i == 0)cout<<result[i]<<" ";
        else
        {
            if(result[i] != result[i-1])cout<<result[i]<<" ";
            else
                continue;
        }
    }

}


int main()
{
    while(1)
    {
        int a,b;
        cin>>a>>b;
        if(a && b )process(a,b);
        else
            break;
    }


    return 0;
}



/**集合思路**/
int main()
{
    int m,n;
    while(cin>>m>>n)
    {
        set<int> s;
        int t;
        for(int i=0;i<m;++i)
        {
            cin>>t;
            s.insert(t);
        }
        for(int i=0;i<n;++i)
        {
            cin>>t;
            s.insert(t);
        }
        set<int>::iterator it = s.begin();
        while(it!=s.end())
        {
            cout<<*it<<" ";
            ++it;
        }
        cout<<endl;
    }
    return 0;
}
