//
// Created by Carla Onate on 28/09/22.
//

#include <map>
#include <set>
#include <string>
#include <iostream>

using namespace std;

#ifndef ALGORITMOS_AVANZADOS_NODE_H
#define ALGORITMOS_AVANZADOS_NODE_H

class Node {
  public:
  map<char, Node*> nextNodes;
  bool endNode = false;
};


#endif //ALGORITMOS_AVANZADOS_NODE_H
