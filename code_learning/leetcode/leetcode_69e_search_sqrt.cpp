#include <iostream>

using namespace std;
/* -------------------------------------------
 * 收获：
 * 折半也能对数字进行拆分 只要符合
 * 连续单调条件
 * 即可使用 提高速度
 * ------------------------------------------*/

int largestNumber(int num)
{
   int l = 1,r = num,mid,dev;
   while(l<r)
   {
       mid = (r-l)/2+1;
       dev = num/mid;
       if(mid == dev)  // 正好是平方根
           return mid;
       else if(mid < dev) // 中位数小了
           l = mid+1;
       else               // 中位数大了
           r = mid-1;
   }

    return mid;
}

int main()
{
    int nums = 11;

    int result = largestNumber(nums);

    return 0;
}