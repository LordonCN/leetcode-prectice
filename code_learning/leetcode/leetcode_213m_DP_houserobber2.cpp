#include <iostream>
#include <vector>

using namespace std;

/* -------------------------------------------
 * 注意：ac 100% 81.12%
 * temp当前位置存储的是可抢劫的最大值 不能是house0 house1的值
 * 递归复杂度为n 分类讨论不增加复杂度
 * 思路:
 * 与198题不同的是将最后一个与第一个连接起来，同时第一个还与第二个相关，所以这里分类讨论。
 * 1-考虑第一项，第二项直接去掉
 * 2-不考虑第一项，即为单链解法同198
 * ------------------------------------------*/

int rob(vector<int>& house)
{
    if(house.empty())return 0;
    if(house.size() == 1)return house[0];
    if(house.size() == 2)return max(house[0],house[1]);

    // 将house[0]当做最后一个房子 不取house[1]
    vector<int>temp{0,house[2]};
    for(int i = 3;i<house.size();i++)
    {
        int maxsum = max(temp[i-2],temp[i-3]+house[i]);
        temp.push_back(maxsum);
    }
    int maxsum = max(temp[temp.size()-1],temp[temp.size()-2]+house[0]);
    temp.push_back(maxsum);


    // 不取house[0] 取house[1]
    vector<int>temp1{house[1],max(house[1],house[2])};// [1,3,1,3,100] 要取两者最大值
    for(int i_ = 3;i_<house.size();i_++)
    {
        int maxsum = max(temp1[i_-2],temp1[i_-3]+house[i_]);
        temp1.push_back(maxsum);
    }
    maxsum = max(temp1[temp1.size()-1],temp1[temp1.size()-2]);
    temp1.push_back(maxsum);


    return max(temp[temp.size()-1],temp1[temp1.size()-1]);
}

int main()
{
    vector<int> house{1,3,1,3,100};

    int result = rob(house);

    return 0;
}