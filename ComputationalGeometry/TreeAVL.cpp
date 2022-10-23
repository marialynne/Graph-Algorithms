// Manuel Camacho Padilla [A0142315]
// Arbol de estructura de datos (AVL)
#include "TreeAVL.h"
 
TreeAVL::TreeAVL(){
  root = nullptr;
}

TreeAVL::~TreeAVL(){
  
}

//getters
NodeAVL* TreeAVL::getRoot(){
  return root;
}

//setters
void TreeAVL::setRoot(NodeAVL* _root){
  root = _root;
}

//funtions 
void TreeAVL::pre_order(NodeAVL* aux){ 
  /*
  Funcion recursiva que imprime los nodos de la estrcutura de arriba a abjo e izquierda a derecha.
  Input: Un objeto tipo NodeAVL
  Output: Nada
  */
  if(aux != nullptr){
    std::cout << aux;
    pre_order(aux->getLeft());
    pre_order(aux->getRight());
  }
}

void TreeAVL::in_order(NodeAVL* aux){
  /*
  Funcion recursiva que imprime los nodos de la estrcutura de manera ordenara. 
  Input: Un objeto tipo NodeAVL
  Output: Nada
  */ 
  if(aux != nullptr){
    in_order(aux->getLeft());
    std::cout << aux;
    in_order(aux->getRight());
  }
}

NodeAVL* TreeAVL::insertAVL(NodeAVL *node, int data, bool &bo, string texto){
  /*
  Funcion que inserta un nodo en un arbol balanceado.  Complejidad: O (log(n))
  Input: Objeto tipo NodeAVL [se analiza]
           Un valor entero [data, valor insertado]
           Un valor boolenao [indica que la altura del arbol a aumentado] 
           Un valor string [texto]
  Output: Un objeto tipo NodeAVL
  */
   NodeAVL *node1, *node2;

  if(node != nullptr){
    if(data < node->getData()){

      node->setLeft(insertAVL(node->getLeft(), data, bo, texto));

      if(bo == true){
        switch(node->getFe()){

          case 1: node->setFe(0); bo = false;
          break;

          case 0: node->setFe(-1);
          break;

          case -1: 
          node1 = node->getLeft();
          if(node1->getFe() < 0){
            node->setLeft(node1->getRight());
            node1->setRight(node);
            node->setFe(0);
            node = node1;
          }
          else{
            node2 = node1->getRight();
            node->setLeft(node2->getRight());
            node2->setRight(node);
            node1->setRight(node2->getLeft());
            node2->setLeft(node1);

            if(node2->getFe() == -1){
              node->setFe(1);
            }
            else{
              node->setFe(0);
            }
            if(node2->getFe() == 1){
              node1->setFe(-1);
            }
            else{
              node1->setFe(0);
            }
            node = node2;
          }
          node->setFe(0);
          bo = false;

          break;
        }
            
      }

    }
    else if(data > node->getData()){

      node->setRight(insertAVL(node->getRight(), data, bo, texto));

      if(bo == true){
        switch(node->getFe()){
          case -1: node->setFe(0); bo = false;
          break;
          case 0: node->setFe(1);
          break;
          case 1:
          node1 = node->getRight();
        
          if(node1->getFe() > 0){
            node->setRight(node1->getLeft());
            node1->setLeft(node);
            node->setFe(0);
            node = node1;
          }
          else{
            node2 = node1->getLeft();
            node->setRight(node2->getLeft());
            node2->setLeft(node);
            node1->setLeft(node2->getRight());
            node2->setRight(node1);

            if(node2->getFe() == 1){
              node->setFe(-1);
            }
            else{
              node->setFe(0);
            }
            if(node2->getFe() == -1){
              node1->setFe(1);
            }
            else{
              node1->setFe(0);
            }
            node = node2;
            
          }
          
          node->setFe(0);
          bo = false;
          break;

        }
 
      }

    }

    else{
      std::cout << "\ninsertAVL[FALSE]: Repeated data." << std::endl;
    }
   
  }
  else{
    node = new NodeAVL(data, 0, nullptr, nullptr, texto);
    bo = true;

  }

  return node;

}



