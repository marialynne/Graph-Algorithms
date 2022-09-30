//
// Created by Carla Onate on 27/09/22.
//

#include "graph.h"

TRIE::TRIE()
{
  // Inicializar el root a un nodo vacio
  this->root = new Node();
}

void TRIE::addText(string text)
{
  Node *currentNode = this->root;
  for (int i = 0; i < text.length(); i++)
  {
    while (currentNode->nextNodes[text[i]])
    { // Mientras haya camino siguelo
      currentNode = currentNode->nextNodes[text[i]];
      // Sigue avanzando en el texto
      i++;
    }
    // Si ya no hay camino haz uno nuevo
    Node *newNode = new Node();
    currentNode->nextNodes[text[i]] = newNode;
    currentNode = newNode;
    currentNode->endNode = true;
    // currentNode->nextNodes['$'] = nullptr;
  }
}

bool TRIE::searchTrie(string text)
{
  Node *currentNode = this->root;
  string resultingSearch = "";

  for (char i : text) // Mientras haya camino siguelo
  {
    resultingSearch += i;
    if (currentNode->nextNodes[text[i]])
      return false;
    currentNode = currentNode->nextNodes[text[i]];
  }

  cout << "Caracteres encontrados: " << resultingSearch;
  if (currentNode->endNode)
    return true;
  return false;
}

void TRIE::printGraph(Node *root)
{
  for (std::pair<const char, Node *> el : root->nextNodes)
  {
    cout << el.first << " ";
    if (el.second != nullptr)
    {
      printGraph(el.second);
      // cout << "\n";
      // std::cout << "Tienen hijos" << std::endl;
    }
  }
}
