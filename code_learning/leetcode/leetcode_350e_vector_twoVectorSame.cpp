#include <iostream>
#include <vector>

using namespace std;

/* -------------------------------------------
 * 双指针 也灵魂
 * ac 91 86
 * ------------------------------------------*/
vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
    if(nums1.size() < nums2.size())swap(nums1,nums2);// 把大的给nums1

    vector<int>output;
    sort(nums1.begin(),nums1.end());
    sort(nums2.begin(),nums2.end());
    for(int i = 0,j = 0;j<nums2.size();j++,i++)
    {
        if(i == nums1.size())break;
        if(nums2.empty())return output;// nums2空了 可以结束
        if(nums1[i]>nums2[j])i--;
        else if(nums1[i]<nums2[j])j--;
        else
            output.push_back(nums1[i]);
    }
    return output;
}
int main()
{
    // 首先准备好nums target
    vector<int> nums1 {0,1,2,7,9};
    vector<int> nums2 {5,7,4,6,8,0,1,2,7,9};

    intersect(nums1,nums2);


    return 0;
}