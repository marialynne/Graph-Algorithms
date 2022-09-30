//
// Created by Carla Onate on 27/09/22.
//

#include "graph.h"


TRIE::TRIE() {
  // Inicializar el root a un nodo vacio
  this->root = new Node();
}

void TRIE::addText(string text) {
  Node* currentNode = this->root;
  for (int i  = 0; i < text.length(); i++) {
    while (currentNode->nextNodes[text[i]]) { // Mientras haya camino siguelo
      currentNode = currentNode->nextNodes[text[i]];
      i++; // Sigue avanzando en el texto
    }
    // Si ya no hay camino haz uno nuevo
    Node *newNode = new Node();
    currentNode->nextNodes[text[i]] = newNode;
    currentNode = newNode;
  }
  currentNode->endNode = true;
}

bool TRIE::searchTrie(string text) {
  cout << "texto a buscar: " << text << "\n";
  Node* currentNode = this->root;
  string resultingSearch;
  int i = 0;
  while (currentNode->nextNodes[text[i]]) { // Mientras haya camino siguelo
    cout << " " << text[i] << " ";
    currentNode = currentNode->nextNodes[text[i]];
    resultingSearch += text[i];
    i++;
  }
  cout << "Caracteres encontrados: " << resultingSearch << " => BOOL:  ";
  //cout << "\n current NODE: " << currentNode->endNode << "\n";
  if (currentNode->endNode)
    return true;
  return false;
}

void TRIE::getGraph(Node* root, int level, map<int, vector<char>> &mapTrie) {
    for (std::pair<const char, Node*> el : root->nextNodes){
      mapTrie[level].push_back(el.first);
      if (!el.second->endNode){
        getGraph(el.second, level + 1, mapTrie);
      }
    }
}

void TRIE::printResultingTrie(map<int, vector<char>> mapTrie) {
  for (pair<const int, vector<char>> level : mapTrie) {
      cout << "Nivel (" << level.first << "):  ";
      for (auto character : level.second) {
        cout << " " << character << " ";
      }
      cout << "\n";
  }
}