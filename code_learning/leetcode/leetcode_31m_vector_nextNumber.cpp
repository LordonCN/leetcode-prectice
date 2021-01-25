#include <iostream>
#include <vector>
#include <algorithm> // 包含reverse

/* -------------------------------------------
 * vector reverse使用
 * 下一个更大数 前一个更小数 从后往前挨个遍历然后翻转的思路很精妙
 * 说不上来为啥
 * ------------------------------------------*/
using namespace std;

int main()
{
    vector<int> array {1,4,7,5,2,6,1};

    cout<<array.size()<<endl;

    /********************************
     *  next bigger one
     *==============================*/
//     只有一个或为空 直接结束
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
                swap(array[slower] , array[prior]);
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