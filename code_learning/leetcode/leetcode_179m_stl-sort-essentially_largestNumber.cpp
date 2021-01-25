#include <iostream>
#include <vector>

using namespace std;
/* -------------------------------------------
 * 收获：
 * 了解了sort本质 可操作性极强 一开始没有成功还是理解不够深入
 * 数字类型判断位数通过转换为string怕暖
 * -------------------------------------------
 * bubble sort
 * 初步完成排序 只能排出首位的大小
 * stl sort 新的思路 - 应用于字符串这种排序
 * 原理：判断传进来的两个数 该怎样排列 换句话说该函数比较了所有元素之间的两两比较 最终返回一个大小比对
 * 此处比如 34 35比较 9 34 比较 9 35比较... 所以才会得出一个完成的顺序
 * ------------------------------------------*/
bool sortCmp(const int a, const int b)
{
    string astring = to_string(a)+to_string(b);
    string bstring = to_string(b)+to_string(a);

    return astring>bstring;
}

void largestNumber(vector<int>&nums)
{
    sort(nums.begin(),nums.end(),sortCmp);

    string output;
    for(auto i : nums)
        output += to_string(i);

    return;
}


int main()
{
    // 首先准备好nums target
    vector<int> nums {4,1,0,6,10,34,9,8,33,24,35};

    largestNumber(nums);

    return 0;
}