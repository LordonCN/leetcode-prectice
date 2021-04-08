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
    vector<int> nums{7,2,9,4,8,11,23,4,5,6,8};
    vector<int>::iterator ite = nums.begin();
    cout<<"the nums's capacity is" <<nums.capacity()<<endl;

    while(ite!=nums.end())
    {
        // 删除4之后 8补了上来
        cout<<"now is "<<nums.capacity()<<endl;
//        if(ite == (nums.begin()+3))// 这是把3之后的全清除
        if(*ite == 4)// 这是把4清除
        {
            ite = nums.erase(ite);
            cout<<"after is "<<nums.capacity()<<endl;
        }
        else
            ite ++;
    }


//    int l = 0,r = nums.size()-1;
//    vector<int> result = quicksort(nums,l,r);
//    vector<int> result = mergesort(nums,l,r);

//    Singleton obj1 = Singleton::getSingleton();
//    Singleton obj2 = Singleton::getSingleton();

//    vector<int>test{6,3,4,6,9,4,3,5,6,7,1,9,5,3};
//    quickSort(test,0,test.size()-1);

//    char a = '\82';


    return 0;
}