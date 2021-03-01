#include <iostream>
#include <vector>

using namespace std;

/* -------------------------------------------
 * 双指针排序 三向切分快速排序法(用于优化快排)
 * 前后两端移动
 * 关键：右端移动后还要判断是否要将小的数字再移动到最前端
 * 二刷问题：i一开始设置为从1开始 一直没有成功 这个地方值得注意
 * ------------------------------------------*/
void sortColors(vector<int> &nums)
{
    if(nums.size()<2)
        return;

    // 双指针
    int zeroOne = 0,oneTwo= nums.size()-1;
    int i = 0;
    while(i<=oneTwo)
    {
        // 左指针与遍历进行交换
        if(nums[i]==0)
        {
            swap(nums[zeroOne],nums[i]);
            zeroOne += 1;
            i += 1;
        }
        // 有指针与遍历进行交换
        else if(nums[i]==2)
        {
            swap(nums[i],nums[oneTwo]);
            oneTwo -= 1;
            // 这里太关键了 如果后面还有0 那么还应该进行一次判断将0放到前面去
            // 意思是i 这里不改变
        }
        else i += 1;
    }
}

int main()
{
    // 首先准备好nums target
    vector<int> nums{0,1,2,2,1,1,0,0,1};

    sortColors(nums);

    return 0;
}