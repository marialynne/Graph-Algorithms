#include <map>
#include <iostream>

using namespace std;

class Node
{
public:
  map<Node *, int> nextNodes; // vertex / number of node
  int weight;                 // weight
  bool visisted;              // is visited?
};
