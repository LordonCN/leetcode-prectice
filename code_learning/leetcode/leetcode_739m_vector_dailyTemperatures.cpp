#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

/* -------------------------------------------
 * 思路：
 * 1、双循环可以
 * 2、参考leetcode155最小栈实现
 * ------------------------------------------*/
vector<int> dailyTemperatures(const vector<int>&temperatures)
{
    vector<int>result;
    for(int i = 0 ;i < temperatures.size();i++)
    {
        result.push_back(0);
        for(int j = i+1;j<temperatures.size();j++)
        {
            if(temperatures[j]>temperatures[i] &&
                result[i] == 0)
            {
                result[i] = j - i;
                break;
            }
        }
    }

    return result;
}

vector<int> dailyTemperaturesMinStack(const vector<int>&temperatures)
{
    stack<int>minstack;
    vector<int>result;

    for(int i = 0 ;i < temperatures.size();i++)
    {
        result.push_back(0);
        while(!minstack.empty())
        {
            int stacktop = minstack.top();
            if(temperatures[i]<=temperatures[stacktop]) break;

            result[stacktop] = i - stacktop;
            minstack.pop();
        }
        minstack.push(i);
    }

    return result;
}

int main()
{
    vector<int> nums{73,74,75,71,69,72,76,73};
    vector<int>result;
    result = dailyTemperaturesMinStack(nums);

    return 0;
}