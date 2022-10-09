#include "node.h"
#include <iostream>
#include <vector>
#include <list>
using namespace std;

class Brelaz
{
public:
    vector<int> colors; // 4
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
