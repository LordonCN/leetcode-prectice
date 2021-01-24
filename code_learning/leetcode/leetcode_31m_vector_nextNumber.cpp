#include <iostream>
#include <vector>
#include <algorithm> // 包含reverse

using namespace std; 

int main()
{
    vector<int> array;
    array.push_back(1);
    array.push_back(4);
    array.push_back(7);
    array.push_back(5);
    array.push_back(2);
    array.push_back(6);
    array.push_back(1);
    cout<<array.size()<<endl;

    /********************************
     *  next bigger one
     *==============================*/
    // 只有一个或为空 直接结束
//    if(array.size() < 2) return 0 ;
//    // 定义双指针
//    int prior = array.size() - 2;
//    while(prior >= 0)
//    {
//        int slower = array.size() - 1;
//        while(slower > prior)
//        {
//            // 前面的数小
//            if(array[prior] < array[slower]){
//                // 交换数值
//                int temp = array[slower];
//                array[slower] = array[prior];
//                array[prior] = temp;
//                // 并将交换位置之后 prior后面的所有数进行反转 并不是排序
//                // 解释为什么用reverse 不用sort:
//                // reverse这是个置换 并没有对大小进行判断来排序 因为在两个while中已经对顺序进行过判断
//                // 所以这里只要颠倒一下顺序即可选出右侧最小值
//                reverse(array.begin() + prior + 1 ,array.end());
//                return 0;
//            }
//            slower --;
//        }
//        prior --;
//    }
//    reverse(array.begin(),array.end());


    /********************************
     *  last small one
     *==============================*/

    // 1472165
    // 只有一个或为空 直接结束
    if(array.size() < 2) return 0 ;
    // 定义双指针
    int prior = array.size() - 2;
    while(prior >= 0)
    {
        int slower = array.size() - 1;
        while(slower > prior)
        {
            // 前面的数大
            if(array[prior] > array[slower]){
                // 交换数值
                int temp = array[slower];
                array[slower] = array[prior];
                array[prior] = temp;
                // 并将交换位置之后 prior后面的所有数交换位置
                reverse(array.begin()+prior+1,array.end());
                return 0;
            }
            slower --;
        }
        prior --;
    }
    reverse(array.begin(),array.end());

    return 0;
}