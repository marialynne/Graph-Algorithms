#include <map>
#include <vector>
#include <set>
#include <iostream>
#include "node.h"
using namespace std;

class Dijkstra
{
public:
  Node *start;

public:
  Dijkstra();

  void addNode(Node *);
  void dijkstraAlgoritm();
  void print();
};
