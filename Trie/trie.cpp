//
// Created by Carla Onate on 23/09/22.
//

#include "graph.h"
#include <regex>
#include <iostream>
using namespace std;

bool regexWord(string word)
{
  const regex expReg("^[a-zA-Z]+$");
  return regex_match(word, expReg);
}

bool regexNumber(string num)
{
  string int_num = "^[0-9]*$";

  regex pattern(int_num);

  if (regex_match(num, pattern))
    return true;
  return false;
}

int main()
{
  TRIE graph;
  int n, m;
  string word;

  cout << "\nBienvenido a TRIE. \n";
  cout << "Ingresa el numero de palabras a insertar: ";
  cin >> n;

  for (int i = 0; i < n; i++)
  {
    cout << "Ingresa la palabra (" << (i + 1) << "): ";
    cin.ignore();
    getline(cin, word);

    if (regexWord(word))
      graph.addText(word);
    else
      cout << "ERROR: Solo se aceptan caracteres de la a - z, minusculas y sin espacios.\n";
  }

  cout << "\nIngresa el numero de palabras a buscar: ";
  cin >> m;

  for (int i = 0; i < m; i++)
  {
    cout << "Ingresa la palabra (" << (i + 1) << "): ";
    cin.ignore();
    getline(cin, word);

    (graph.searchTrie(word)) ? cout << "\tTRUE\n" : cout << "\tFALSE\n";

    /*  if (regexWord(word))
       (graph.searchTrie(word)) ? cout << "\tTRUE\n" : cout << "\tFALSE\n";
     else
       cout << "ERROR: Solo se aceptan caracteres de la a - z. \n"; */
  }

  graph.printGraph(graph.root);
}
