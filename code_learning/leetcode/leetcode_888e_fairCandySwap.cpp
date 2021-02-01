#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

/* -------------------------------------------
 * 亮点：
 * 使用accumelate迭代器计算vector sum
 * accumulate(a.begin(),a.end(),0)
 * ------------------------------------------*/

void candySwap(vector<int> &a,vector<int>&b)
{
    vector<int>result;

    for(int A=0;A<a.size();A++)
    {
        for(int B=0;B<b.size();B++)
        {
            swap(a[A],b[B]);
            // 统计交换后手里的糖果数量
            if(accumulate(a.begin(),a.end(),0) == accumulate(b.begin(),b.end(),0))
            {
                result.push_back(a[A]);
                result.push_back(b[B]);
                return ;
            }
            else
                swap(a[A],b[B]); // 本次交换无效 再换回去
        }
    }
    return ;
}


int main()
{
    // 首先准备好nums target
    vector<int> a{1,3};
    vector<int> b{2};


    candySwap(a,b);

    return 0;
}