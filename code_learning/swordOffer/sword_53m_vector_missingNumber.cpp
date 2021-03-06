#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*************************************************************************
* offer40 ac 84 79 3.3
*======================================================================*/

int missingNumber(vector<int>& nums) {
    if(nums[0] == 1)return 0;
    int length = 0;
    vector<int>temp = nums;
    bool sign = false;
    for(int i = 1;i<nums.size();i++)
    {
        nums[i] = nums[i]-temp[i-1];
        if(nums[i] == 2)
        {
            length = i;
            sign = true;
            break;
        }
    }
    if(sign)
        return accumulate(nums.begin(),nums.begin()+length,0)+1;),nums.begin()+length,0)+1;
    else
    return temp[nums.size()-1]+1;
}


int main()
{
    vector<int> nums{0,1,2,3,4,5,6,7,9};

    missingNumber(nums);

    return 0;
}
