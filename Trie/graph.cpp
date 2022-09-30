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
  currentNode->nextNodes['$'] = nullptr;
}

void TRIE::searchTrie(string text) {
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
  cout << " || \n";
  cout << "Caracteres encontrados: " << resultingSearch << "\n";
}

void TRIE::printGraph(Node* root) {
    for (std::pair<const char, Node*> el : root->nextNodes){
      cout << el.first << " ";
      if (el.second != nullptr){
        printGraph(el.second);
        //std::cout << std::endl;
        //std::cout << "Tienen hijos" << std::endl;
      }
    }
}
