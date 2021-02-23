#include <iostream>
#include <vector>

using namespace std;

/* -------------------------------------------
 * 注意：
 * temp当前位置存储的是可抢劫的最大值 不能是house0 house1的值
 * ------------------------------------------*/

int rob(vector<int>& house)
{
    if(house.empty())return 0;
    if(house.size() == 1)return house[0];
    if(house.size() == 2)return max(house[0],house[1]);

    vector<int>temp{house[0],max(house[0],house[1])};
    for(int i = 2;i<house.size();i++)
    {
        int maxsum = max(temp[i-1],temp[i-2]+house[i]);
        temp.push_back(maxsum);
    }

    return temp[temp.size()-1];
}

int main()
{
    vector<int> house{1,3,1,3,100};

    int result = rob(house);

    return 0;
}