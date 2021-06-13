#include <iostream>
#include "graph.h"

using namespace std;

int main()
{
    BFSgraph(example_graph,'A');
    cout<<"-------------------"<<endl;
    DFSgraph(example_graph,'A');

    return 0;
}