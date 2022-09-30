//
// Created by Carla Onate on 27/09/22.
//

#ifndef ALGORITMOS_AVANZADOS_GRAPH_H
#define ALGORITMOS_AVANZADOS_GRAPH_H

#include <map>
#include <set>
#include <string>
#include <iostream>
#include "node.h"

using namespace std;

class TRIE {
  public:
    Node* root;

  public:
    TRIE();
    void addText(string);
    void searchTrie(string);
    void printGraph(Node*);
};

#endif //ALGORITMOS_AVANZADOS_GRAPH_H

