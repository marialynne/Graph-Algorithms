#include <iostream>
#include <map>
using namespace std;

class Node
{
public:
    map<Node *, int> nextNodes; // AddressNode | indentifier
    int color;
    int edges; // nextNodes.size()
};
