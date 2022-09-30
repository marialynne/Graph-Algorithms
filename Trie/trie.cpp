//
// Created by Carla Onate on 23/09/22.
//

#include "graph.h"
using namespace std;

int main () {
  TRIE graph;
  graph.addText("holas");
  graph.addText("hola");
  graph.addText("hueva");
  graph.addText("abbc");
  graph.addText("acda");
  graph.searchTrie("hola");
  //graph.searchTrie("humo");
  graph.printGraph(graph.root);
}

