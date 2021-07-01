#include <iostream>

using namespace std;
/* -------------------------------------------
 * 收获：
 * 折半也能对数字进行拆分 只要符合
 * 连续单调条件
 * 即可使用 提高速度
 * ------------------------------------------*/

//int largestNumber(int num)
//{
//   int l = 1,r = num,mid,dev;
//   while(l<r)
//   {
//       mid = (r-l)/2+1;
//       dev = num/mid;
//       if(mid == dev)  // 正好是平方根
//           return mid;
//       else if(mid < dev) // 中位数小了
//           l = mid+1;
//       else               // 中位数大了
//           r = mid-1;
//   }
//
//    return mid;
//}

class Solution {
public:
    int mySqrt(int x) {
         //*****************  methord1 ***************** //
         int mid = x/2+1;
         for(double i = 0;i<=mid;i++)
         {
             if(i*i==x)return i;
             else if(i*i>x)return i-1;
         }
         return x;

         //*****************  methord2*****************  //
         long r = 1;
         while(r * r <= x)
         {
             r+=1;
         }
         return r-1;

        // ***************** methord3*****************  //
        // 先两倍两倍扩大地找区间搜索的右边界
        long r = 1;
        while(r * r < x) r = r << 1;
        if(r * r == x) return (int)r;
        // 左边界 除以二即可
        long l = r >> 1;
        while(l < r){
            if(l + 1 == r) return (int)l;// x=1
            long mid = (l + r) / 2;// 二分取中点
            if(mid * mid == x) return (int)mid;
            else if(mid * mid > x){
                 if(l + 1 == mid) return (int)l;// 剪枝提高4ms
                r = mid;
            }
            else{
                 if(mid + 1 == r) return (int)mid;
                l = mid;
            }
        }
        return (int)l;
    }
};



int main()
{
    int nums = 11;

    int result = largestNumber(nums);

    return 0;
}