#include <iostream>
#include <vector>
#include "sort.h"

using namespace std;

/* -------------------------------------------
 * mergesort
 * ------------------------------------------*/
vector<int> mergesort(vector<int>&nums,int l,int r)
{
    if(l>=r-1) return nums; //直到分解成只有一个元素
    //1、首先进行拆分
    int mid = (l+r)/2;
    mergesort(nums,l,mid);
    mergesort(nums,mid,r);
    //TODO:2、合并操作

    return nums;
}

void quickSort(vector<int>&nums,int l,int r){
    int mid,first = l,end = r,value;
    if(first<end)
    {
        value = nums[l];
        while(l<r && nums[r]>=value) r--;
        if(l<r) swap(nums[l++],nums[r]);
        while(l<r && nums[l]<=value) l++;
        if(l<r) swap(nums[l],nums[r--]);
    }
    mid = l;
    if(first<mid)quickSort(nums,first,mid-1);
    if(end>mid)quickSort(nums,mid+1,end);
    return ;
}

/**singleton 引用方法创建**/
class Singleton{
private:
    Singleton(int n){debugNumber = n;};
    int debugNumber;// debug方便查看
public:
    static Singleton& getSingleton(int n)
    {
        static Singleton obj(n);
        return obj;
    }
};

/**类模板测试 先把类写出来 再套模板修改**/
template<class T>
class A{
private:
    T number;
public:
    A():number(0){};
    virtual ~A(){};// 这里不能等于0 要不就成了纯虚
    A(T n){number = n;};
    A(const A&);
    A & operator=(const A&);
    void getNumber()const {cout<<number<<endl;};

};
// 不需要返回值 声明里面没写temp 这里拿上还能用
template<class T>
A<T>::A(const A &temp) {
    this->number = temp.number;
}

template<class T>
A<T> & A<T>::operator=(const A &temp) {
    if(&temp == this)return *this;
    this->number = temp.number;
    return *this;
}



#include <iostream>
#include <iomanip>
#include <unordered_map>
#include <unordered_set>
#include <array>
#include <vector>
#include <utility>
#include <queue>
#include <tuple>
#include <algorithm>
#include <cstdlib>

struct SimpleGraph {
    std::unordered_map<char, std::vector<char> > edges;

    std::vector<char> neighbors(char id) {
        return edges[id];
    }
};

SimpleGraph example_graph {{
                                   {'A', {'B'}},
                                   {'B', {'C'}},
                                   {'C', {'B', 'D', 'F'}},
                                   {'D', {'C', 'E'}},
                                   {'E', {'F'}},
                                   {'F', {}},
                           }};

struct GridLocation {
    int x, y;
};

#include <vector>
#include <iostream>
#include <set>

int main()
{
//     首先准备好nums target
//    vector<int> nums{7,2,9,4,8,10,1};
//    int l = 0,r = nums.size()-1;
//    vector<int> result = quicksort(nums,l,r);
//    vector<int> result = mergesort(nums,l,r);

//    Singleton obj1 = Singleton::getSingleton();
//    Singleton obj2 = Singleton::getSingleton();

//    vector<int>test{6,3,4,6,9,4,3,5,6,7,1,9,5,3};
//    quickSort(test,0,test.size()-1);

//    char a = '\82';


        int sum = 0;
        int ans = 0;
        cin >> sum;

        vector<vector<string>>temp(sum,vector<string>(2,""));
        for (int i = 0; i < sum; i++)
        {
            cin >> temp[i][0] >> temp[i][1];
        }

        vector<bool> visited(sum, false);
        vector<set<string>>result;

        while (sum--) {
            set<string>a;
            for (int i = 0; i < sum; i++)
            {
                if (a.empty() && visited[i] == false)
                {
                    a.insert(temp[i][0]); a.insert(temp[i][1]);// 没有添加
                    visited[i] = true;
                    continue;
                }

                if (a.find(temp[i][0]) != a.end() || a.find(temp[i][1]) != a.end() && visited[i] == false) {
                    a.insert(temp[i][0]);
                    a.insert(temp[i][1]);
                    visited[i] = true;
                }
            }
            if (!a.empty()) result.push_back(a);
        }
        cout << result.size();




    return 0;
}