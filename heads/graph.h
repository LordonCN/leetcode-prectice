#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <iomanip>
#include <unordered_map>
#include <unordered_set>
#include <array>
#include <vector>
#include <utility>
#include <queue>
#include <stack>
#include <tuple>
#include <algorithm>
#include <cstdlib>

using namespace std;

struct SimpleGraph {
    std::unordered_map<char, std::vector<char> > edges;  // A
    std::vector<char> neighbors(char id) {       // B,C
        return edges[id];
    }
};

// ABCDEFG
// 1234567
SimpleGraph example_graph {{
       {'A', {'B','C'}},
       {'B', {'D','F'}},
       {'C', {'G'}},
       {'D', {'E'}},
       {'E', {}},
       {'F', {}},
       {'G', {'H'}},
        }};

struct GridLocation {
    int x, y;
};

// 深度优先
std::unordered_set<char> reached;
void DFSgraph(SimpleGraph graph, char start) {
    if(reached.empty())cout<<start<<endl;// 打印第一个点
    reached.insert(start);
    // 循环将邻居都添加到图中
    for (char next : graph.neighbors(start)) {// 从邻居里面找一个出来
        if (reached.find(next) == reached.end()) { // 如果现在还没有到达过这个点  set.end()指不存在该值
            cout<<next<<endl;
            DFSgraph(graph,next);
        }
    }
}

// 广度优先
void BFSgraph(SimpleGraph graph, char start) {
    std::queue<char> frontier;
    frontier.push(start);// 第一项入队列
    std::unordered_set<char> reached;

    while (!frontier.empty()) {
        char current = frontier.front();
        frontier.pop();
        reached.insert(current);
        std::cout << "Visiting " << current << '\n';

        // 循环将邻居都添加到图中
        for (char next : graph.neighbors(current)) {// 从邻居里面找一个出来
            if (reached.find(next) == reached.end()) { // 如果现在还没有到达过这个点  set.end()指不存在该值
                frontier.push(next); //
                reached.insert(next);
            }
        }
    }
}


#endif