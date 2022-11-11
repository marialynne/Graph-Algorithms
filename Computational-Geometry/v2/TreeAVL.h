// Manuel Camacho Padilla [A0142315]
// Arbol de estructura de datos (AVL)
#pragma once
#include <iostream>
#include <string>
#include "NodeAVL.h"

class TreeAVL{
  NodeAVL* root;

public:
  //defualt 
  TreeAVL();
  ~TreeAVL();

  //getters
  NodeAVL* getRoot();

  //setters
  void setRoot(NodeAVL*);

  //function 
  NodeAVL *insertAVL(NodeAVL*, int, bool&, string);

  void pre_order(NodeAVL*);
  void in_order(NodeAVL*);

};