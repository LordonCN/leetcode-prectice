#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <algorithm>

using namespace std;

/* -------------------------------------------
 * 重点：
 * vector函数联系 逻辑训练
 * ------------------------------------------*/

vector<string> findIt(const vector<vector<string>>& nums)
{
    // 出栈后保存结果
    vector<string>result;
    vector<string>resultFinal;
    // 循环中压栈
    stack<string>sequence;
    // 可选内容 找到后压栈擦除
    vector<vector<string>>temp;
    int test = 0;

    for(int i = 0;i<nums.size();i++) // 所有的都要测试一遍是否都能作为出发点
    {
        temp = nums;
        sequence.push(temp[i][0]);
        sequence.push(temp[i][1]);
        temp.erase(temp.begin()+i,temp.end()-nums.size()+1+i);
        while(!temp.empty()) // 序列可行性分析阶段 所给样例测试通过
        {
            // 这里如果没有可连接的情况的时候需要退出循环
            test++; if(test>nums.size()) break;

            // 循环查找可拼接的选相 并及时擦除
            for(int A = 0;A<temp.size();A++)
            {
                if(temp[A][0] == sequence.top())
                {
                    sequence.push(temp[A][1]);
                    temp.erase(temp.begin()+A,temp.end()-temp.size()+1+A);
                }
            }
        }
        test = 0;

        // 如果所有都连续到了一起 添加当前结果到stack
        while(!sequence.empty())
        {
            result.push_back(sequence.top());
            sequence.pop();
        }
        // 出栈添加顺序是反的 翻转一下
        reverse(result.begin(),result.end());

        // 更新最终结果
        if(resultFinal.empty() ||
          (resultFinal[0]<result[0]&&result.size()==resultFinal.size()))
            resultFinal = result;

        result.erase(result.begin(),result.end());
    }


    return resultFinal;
}

int main()
{
    // 首先准备好nums target
    vector<vector<string>> nums{{"MCU","LHR"},{"JFK","MCU"},{"SFO","SJC"},{"LHR","SFO"}};
    // 先按首字母排个序 方便选择多种可能性中字母序最小的
    sort(nums.begin(),nums.end());

    findIt(nums);

    return 0;
}