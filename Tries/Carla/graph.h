//
// Created by Carla Onate on 27/09/22.
//

#ifndef ALGORITMOS_AVANZADOS_GRAPH_H
#define ALGORITMOS_AVANZADOS_GRAPH_H

#include <map>
#include <unordered_map>
#include <set>
#include <string>
#include <vector>
#include <iostream>
#include "node.h"

using namespace std;

class TRIE {
  public:
    Node* root;

  public:
    TRIE();
    void addText(string);
    bool searchTrie(string);
    void getGraph(Node*, int, map<int, vector<char>>&);
    void printResultingTrie(map<int, vector<char>>);
};

#endif //ALGORITMOS_AVANZADOS_GRAPH_H

