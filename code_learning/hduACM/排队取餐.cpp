#include <iostream>
#include <vector>

using namespace std;

int main()
{

    // 题目一 排队取餐
    /**input**/
    int sum = 0;
    cin >> sum ;
    vector<vector<int>>output;
    while(sum--)
    {
        int temp;
        cin>>temp;

        vector<vector<int>>store(temp,vector<int>(2,0));
        for(int i = 0;i<temp;i++)
        {
            cin>>store[i][0]>>store[i][1];// 读进来队列
        }

        bool timeNow = true;//当前时间
        vector<int>result(temp,0);// 存放拿到的时间
        vector<bool>state(temp,true);

        for(int i = 1;i<10;i++)// 第i个时间点
        {
            for(int t = 0;t<temp;t++)// 第t个人
            {

                if(state[t] && store[t][1]>=i)
                {
                    result[t] = i;
                    state[t] = false;
                    break;
                }
            }
        }
        output.push_back(result);
    }
    for(int t = 0;t<output.size();t++)
    {
        for(int i = 0;i<output[t].size();i++)
            cout<<output[t][i]<<' ';
        cout<<endl;
    }


    return 0;
}
