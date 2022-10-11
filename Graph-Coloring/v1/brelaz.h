#include "node.h"
#include <iostream>
#include <vector>
#include <list>
#include <queue>
using namespace std;

class Brelaz
{
public:
    vector<int> colors; // 4
    priority_queue<pair<int, int>> pq;
    list<Node *> unorderedNodes;
    list<Node *> orderedNodes;
    vector<int> sums;

    Brelaz();
    void inputData();
    void dataToEdges();
    void addEdge(int FromNode, int ToNode); // recive edges and create nodes, then store it in unorderedNodes
    void orderNodes();
    void print();
};
