#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main()
{


        int sum = 0;
        int ans = 0;
        cin >> sum;

        vector<vector<string>>temp(sum,vector<string>(2,""));
        for (int i = 0; i < sum; i++)
        {
            cin >> temp[i][0] >> temp[i][1];
        }

        vector<bool> visited(sum, false);
        vector<set<string>>result;

        while (sum--) {
            set<string>a;
            for (int i = 0; i < sum; i++)
            {
                if (a.empty() && visited[i] == false)
                {
                    a.insert(temp[i][0]); a.insert(temp[i][1]);// 没有添加
                    visited[i] = true;
                    continue;
                }

                if (a.find(temp[i][0]) != a.end() || a.find(temp[i][1]) != a.end() && visited[i] == false) {
                    a.insert(temp[i][0]);
                    a.insert(temp[i][1]);
                    visited[i] = true;
                }
            }
            if (!a.empty()) result.push_back(a);
        }
        cout << result.size();




    return 0;
}