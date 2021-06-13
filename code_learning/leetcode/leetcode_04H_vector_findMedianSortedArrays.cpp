#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

/* -------------------------------------------
 * 两个数组合并排序后直接进行索引即可  ac 54 22
 /*-------------------------------------------*/
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    for(int i = 0;i<nums2.size();i++)
        nums1.push_back(nums2[i]);
    sort(nums1.begin(),nums1.end());
    int length = nums1.size();
    if(length%2 == 0)
    {
        double a = nums1[length/2] / 1.0;
        double b = nums1[length/2-1] / 1.0;
        double out =(a+b)/2.0;
        return out;
    }
    else return nums1[length/2];
}
int main()
{
    // 首先准备好nums target
    vector<int>num1{1,2};
    vector<int>num2{3,4};
    findMedianSortedArrays(num1, num2);

    return 0;
}
