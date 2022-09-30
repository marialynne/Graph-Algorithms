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

  cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
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
      cout << graph.searchTrie(word) << "\n";
      i++;
    } else {
      cout<<"ERROR: Solo se aceptan caracteres de la a - z. \n";
    }
    cout<<"\n";
  }
}

