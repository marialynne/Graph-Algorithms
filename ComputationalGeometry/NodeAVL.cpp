// Manuel Camacho Padilla [A0142315]
// Arbol de estructura de datos (AVL)
#include <iostream>
#include "NodeAVL.h"
using namespace std;

NodeAVL::NodeAVL(){
  data = 0;
  fe = 0;
  left = nullptr;
  right = nullptr;
}

NodeAVL::~NodeAVL(){}


NodeAVL::NodeAVL(int _data, int _fe, NodeAVL* _left, NodeAVL* _right, string _texto){
  data = _data;
  fe = _fe;
  left = _left;
  right = _right;
	texto = _texto;
}
  
//getters
int NodeAVL::getData(){
  return data;
}
int NodeAVL::getFe(){
  return fe;
}
NodeAVL* NodeAVL::getLeft(){
  return left;
}
NodeAVL* NodeAVL::getRight(){
  return right;
}
string NodeAVL::getTexto() {
  return texto;
}

//setters
void NodeAVL::setData(int _data){
  data = _data;
}
void NodeAVL::setFe(int _fe){
  fe = _fe;
}
void NodeAVL::setLeft(NodeAVL* _left){
  left = _left;
}
void NodeAVL::setRight(NodeAVL* _right){
  right = _right;
}
void NodeAVL::setTexto(string _texto) {
  texto = _texto;
}

//operators
std::ostream& operator  << (std::ostream& out, NodeAVL* n){
  //out << "\tDato: " << n->getData() << " ";
  //out << "\tFe: " << n->getFe() << "\n";
  out << n->getTexto() << "\n";
  return out;
}
