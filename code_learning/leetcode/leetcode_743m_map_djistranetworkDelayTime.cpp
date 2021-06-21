#include <iostream>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;
typedef pair<int,int> pii;
int Djistra()
{
    vector<vector<int>>times{{2,1,1},{2,3,1},{3,4,1}};
    int n = 4, k = 2;
    // 用于存储第i个索引点到目标点的距离
    vector<pii>g[n+1];
    for(auto t:times)
        g[t[0]].emplace_back(t[1],t[2]);

    const int inf = 1e9;
    // 默认初始化距离为无穷大
    vector<int> dist(n + 1, inf);
    // 当前点到自己的距离
    dist[k] = 0;

    // attention:小顶堆 从当前所有可选项中找到最短距离
    priority_queue<pii, vector<pii>, greater<pii> > pq;
    pq.emplace(0, k);

    int point, v, w;
    while (!pq.empty()) {
        pii p = pq.top();
        pq.pop();
        // 当前点id
        point = p.second;
        // 遍历当前点所连接的所有点
        for (auto& to : g[point]) {
            v = to.first;
            w = to.second;
            // 更新到相邻点之间的距离
            if (dist[v] > dist[point] + w) {
                dist[v] = dist[point] + w;
                // 保存 总距离,目标点 到 openlist中
                pq.emplace(dist[v], v);
            }
        }
    }
    int ans = *max_element(dist.begin() + 1, dist.end());
    return ans == inf ? -1 : ans;
}

int main()
{
    int i = Djistra();
    return 0;
}