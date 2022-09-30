//
// Created by Carla Onate on 23/09/22.
//

#include "graph.h"
#include <regex>
#include <iostream>
using namespace std;

bool regexWord(string word){
  const regex expReg("^[a-zA-Z]+$");
  return regex_match(word, expReg);
}

bool regexNumber(string numb){
  const regex expReg("^[0-9]+$");
  return regex_match(numb, expReg);
}

int main () {
  TRIE graph;
  int i = 0;
  int n, m;
  cout<<"\nBienvenido a TRIE. \n";
  cout<<"Ingresa el numero de palabras a insertar: \n";
  cin >> n;

  //cin.ignore(10000, '\n');
  //fflush(stdin);

  while(i < n) {
    string word;
    cout<<"Ingresa la palabra ("<<(i + 1)<<"): \n";
    cin.ignore();
    getline(cin, word);
    // cout<<word << "\n";
    //cin.clear();
    //fflush(stdin);
    if(regexWord(word) == true) {
      graph.addText(word);
      i += 1;
    } else {
      cout<<"ERROR: Solo se aceptan caracteres de la a - z, minusculas y sin espacios.\n";
    }
  }
  cout<<"\n";

  cout<<"Ingresa el numero de palabras a buscar: ";
  cin >> m;

  if (!regexNumber(to_string(m))) {
    cout << "ERROR: Solo se aceptan numeros \n";
    exit(0);
  }

  i = 0;
  while(i < m) {
    string word;
    cin>>word;
    //cin.ignore();
    //getline(cin, word);

    if (regexWord(word)) {
      cout << "Encontrado: " << "\n";
      graph.searchTrie(word);
      graph.printGraph(graph.root);
      m++;
    } else {
      cout<<"ERROR: Solo se aceptan caracteres de la a - z. \n";
    }
    cout<<"\n";
  }

  /*graph.addText("holas");
  graph.addText("hola");
  graph.addText("hueva");
  graph.addText("abbc");
  graph.addText("acda");
  graph.searchTrie("hola"); */
  //graph.searchTrie("humo");
  // graph.printGraph(graph.root);
}

