#include <iostream>
#include <vector>

using namespace std;

int sortWay = 2;
/* -------------------------------------------
 * STL sort
 * ------------------------------------------*/
bool sortCmp(const int a,const int b)
{
    return a < b; // 升序
}

/* -------------------------------------------
 * bubble sort
 * ------------------------------------------*/
void bubbleSort(vector<int> &nums)
{
    for(int low = 0; low < nums.size()-1; low++)
    {
        for(int high = low + 1; high < nums.size() ; high++)
        {
            if(nums[high]<nums[low])
                swap(nums[low],nums[high]);
        }

    }

}

/* -------------------------------------------
 * quick sort
 * ------------------------------------------*/
int partition(vector<int>&nums,int i,int j)
{
    int middleVal = nums[i];
    // stop when i == j
    while(i<j)
    {
        // swap left vector
        while(middleVal<nums[j] && j>i)
        {
            j -= 1;
        }
        if(j>i) swap(nums[i++],nums[j]);
        // swap right
        while(middleVal>nums[i] && j>i)
        {
            i += 1;
        }
        if(j>i) swap(nums[i],nums[j--]);
    }
    return i;

}

void quickSort(vector<int> &nums,int begin,int end)
{
    if(begin<end)
    {
        int mid = partition(nums,begin,end);
        quickSort(nums,0,mid-1); // begin == middle now
        quickSort(nums,mid+1,end);
    }

}


void findKthNumber(vector<int> &nums,int K)
{
    if(nums.size()<2)
        return;
    switch(sortWay)
    {
        case 1:
            sort(nums.begin(),nums.end(),sortCmp);
            break;
        case 2:
            bubbleSort(nums);
            break;
        case 3:
            quickSort(nums,0,nums.size()-1);
            break;
        default:
            break;
    }
    cout<<nums[K]<<endl;
}

int main()
{
    // 首先准备好nums target
    vector<int> nums {0,4,1,6,9,8,13};

    int k = 3;
    findKthNumber(nums,k);

    return 0;
}