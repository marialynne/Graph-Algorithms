//
// Created by Carla Onate on 23/09/22.
//

#include "graph.h"
#include <regex>
#include <iostream>
using namespace std;

bool regexWord(string word){
  regex expReg("^[a-zA-Z]+$");
  return regex_match(word, expReg);
}

bool regexNumber(string numb){
  regex expReg("^\\d+$/");
  return regex_match(numb, expReg);
}

// Funcion que recibe un string y lo cicla para validar que sea un digito, regresa un bool
bool validateDigit(string digit) {
  for (auto character : digit) {
    if (!isdigit(character)) return false;
  }
  return true;
}

int main () {
  TRIE graph;
  map<int, vector<char>> resultingTrie;
  int nNumber = 0, mNumber = 0, i = 0;
  string n, m;
//  graph.addText("tosana");
//  graph.addText("torta");
//  graph.addText("taco");
//  graph.addText("topo");
//  graph.addText("topotastico");
//  graph.getGraph(graph.root, 0, resultingTrie);
//  graph.printResultingTrie(resultingTrie);

  cout<<"\nBienvenido a TRIE. \n";
  cout<<"Ingresa el numero de palabras a insertar: \n";
  cin >> n;

  if (!validateDigit(n)) {
    cout<<"ERROR: No es numero \n";
    exit(0);
  }
  nNumber = stoi(n);
  cout << nNumber << "\n";
  while(i < nNumber) {
    string word;
    cout<<"Ingresa la palabra ("<<(i + 1)<<"): \n";
    cin.ignore();
    cin >> word;
    if(regexWord(word) == true) {
      graph.addText(word);
      i++;
    } else {
      cout<<"ERROR: Solo se aceptan caracteres de la a - z, minusculas y sin espacios.\n";
    }
  }
  cout<<"\n";

  // Mostrar TRIE generado
  cout << "TRIE: \n";
  graph.getGraph(graph.root, 0, resultingTrie);
  graph.printResultingTrie(resultingTrie);

  cout<<"Ingresa el numero de palabras a buscar: ";

  cin.ignore(INT_MAX, '\n');
  cin >> m;

  if (!validateDigit(m)) {
    cout<<"ERROR: No es numero \n";
    exit(0);
  }
  mNumber = stoi(m);
  cout << mNumber << "\n";
  i = 0;
  while(i < mNumber) {
    string word;
    cin>>word;

    if (regexWord(word)) {
      (graph.searchTrie(word)) ? (cout << "VERDADERO \n") : (cout << "FALSO \n");
      i++;
    } else {
      cout<<"ERROR: Solo se aceptan caracteres de la a - z. \n";
    }
    cout<<"\n";
  }
}

