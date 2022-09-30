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
  graph.addText("abbc");
  graph.addText("acdf");
  graph.addText("holoo");
  graph.addText("halos");
  cout << "TRIE: \n";
  //map<int, vector<char>> resultingTrie;
  map<int, vector<char>> resultingTrie;
  graph.getGraph(graph.root, 0, resultingTrie);
  graph.printResultingTrie(resultingTrie);
  cout << graph.searchTrie("abbc") << "\n";
  cout << graph.searchTrie("acdf")  << "\n";
  cout << graph.searchTrie("hol")  << "\n";
  cout << graph.searchTrie("halos") << "\n";
  cout << graph.searchTrie("gato") << "\n";
//  int i = 0;
//  string n, m;
//  int mNumber, nNumber;
//  cout<<"\nBienvenido a TRIE. \n";
//  cout<<"Ingresa el numero de palabras a insertar: \n";
//  cin >> n;
//
//  if (!validateDigit(n)) {
//    cout<<"ERROR: No es numero \n";
//    nNumber = stoi(n);
//  }
//
//  while(i < nNumber) {
//    string word;
//    cout<<"Ingresa la palabra ("<<(i + 1)<<"): \n";
//    cin.ignore();
//    getline(cin, word);
//    if(regexWord(word) == true) {
//      graph.addText(word);
//      i++;
//    } else {
//      cout<<"ERROR: Solo se aceptan caracteres de la a - z, minusculas y sin espacios.\n";
//    }
//  }
//  cout<<"\n";
//
//  cout<<"Ingresa el numero de palabras a buscar: ";
//  cin >> m;
//
//  if (!validateDigit(m)) {
//    cout<<"ERROR: No es numero \n";
//    mNumber = stoi(m);
//  }
//
//  i = 0;
//  while(i < mNumber) {
//    string word;
//    cin>>word;
//
//    if (regexWord(word)) {
//      cout << "Encontrado: " << "\n";
//      graph.searchTrie(word);
//      graph.printGraph(graph.root);
//      i++;
//    } else {
//      cout<<"ERROR: Solo se aceptan caracteres de la a - z. \n";
//    }
//    cout<<"\n";
//  }
}

