#include <iostream>
#include <string>
#include <algorithm>
#include <queue>

/* -------------------------------------------
 * 622 一边画图一边写通过
 * 重点：
 * step 1: 先将相关点存储到数组graph中
 * step 2: 创建距离索引 存储当前点到其余点的最近距离
 * step 3:
 * ------------------------------------------*/
using namespace std;
typedef pair<int,int> pii;
int Djistra()
{
    vector<vector<int>>times{{2,1,1},{2,3,1},{3,4,1}};
    int n = 4, k = 2;
    // 用于存储第i个索引点到目标点的距离
    vector<pii>graph[n+1];
    for(auto t:times)
        graph[t[0]].emplace_back(t[1],t[2]);

    const int inf = 1e9;
    // 默认初始化距离为无穷大
    vector<int> dist(n + 1, inf);
    // 当前点到自己的距离
    dist[k] = 0;

    // attention:小顶堆 从当前所有可选项中找到最短距离
    // 默认按照首项进行排列
    priority_queue<pii, vector<pii>, greater<pii> > que;
    que.emplace(0, k);

    int point, id, w;
    while (!que.empty()) {
        auto p = que.top();
        que.pop();
        // select point from openlist
        point = p.second;
        // 遍历当前点所有指向的所有连接点
        for (auto& to : graph[point]) {
            id = to.first;// 目标点id
            w = to.second;// point 到 id 的距离 非总路程
            // 计算总距离并将id加入到openlist
            if (dist[id] > dist[point] + w) {
                dist[id] = dist[point] + w;
                que.emplace(dist[id], id);// 距离在前 优先队列按照距离排序
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