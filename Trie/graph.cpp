//
// Created by Carla Onate on 27/09/22.
//

#include "graph.h"

// Funcion para inicializar un objeti tipo TRIE
TRIE::TRIE() { // O(1)
  // Inicializar el root a un nodo vacio
  this->root = new Node();
}

// Funcion que recibe el texto a agregar y lo cicla para irlo agregando en el arbol TRIE
void TRIE::addText(string text) { // O(n)
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

// Funcion que recibe el texto a buscar lo cicla, con cada caracter va avanznando en el arbol TRIE hasta encontrar o no encontrar la palabra, resera un bool
bool TRIE::searchTrie(string text) { // O(n)
  cout << "texto a buscar: " << text << "\n";
  Node* currentNode = this->root;
  string resultingSearch;
  int i = 0;
  while (currentNode->nextNodes[text[i]]) { // Mientras haya camino siguelo
    cout << " " << text[i] << " (Nodo:  " << currentNode << " )" << " ";
    currentNode = currentNode->nextNodes[text[i]];
    resultingSearch += text[i];
    i++;
  }
  cout << " => Encontrado:  ";
  if (currentNode->endNode && resultingSearch == text)
    return true;
  return false;
}

// Funcion recursiva que recibe el nodo actual, nivel dentro del arbol y un map para guardar los valores del arbol por nivel.
// Sigue todos los caminos posibles dentro del arbol
void TRIE::getGraph(Node* root, int level, map<int, vector<char>> &mapTrie) { // O(branches^depth)
    for (std::pair<const char, Node*> el : root->nextNodes){
      mapTrie[level].push_back(el.first);
      cout << " " << el.first << " ";
      if (!el.second->nextNodes.empty()){
        getGraph(el.second, level + 1, mapTrie);
      } else {
        cout << " $\n";
      }
    }
}

// Funcion que recibe un map y lo cicla para imprimir los valores que tiene dentro
void TRIE::printResultingTrie(map<int, vector<char>> mapTrie) { // O(n*m)
  for (pair<const int, vector<char>> level : mapTrie) {
      cout << "Nivel (" << level.first << "):  ";
      for (auto character : level.second) {
        cout << " " << character << " ";
      }
      cout << "\n";
  }
}

