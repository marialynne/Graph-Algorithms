/*
Manuel Camacho Padilla [A01423135]

Una aplicación que realice la siguiente secuencia de operaciones utilizando tus DTA ABB y AVL. No  construyas un menú.
- Utiliza el archivo de entrada Bitacora.txt que utilizaste en la actividad integradora anterior.
- Pregunta al usuario la cantidad de registros (N) del archivo que desea utilizar para construir las estructuras de datos. Valida que N sea un número positivo.
- Construye un ABB y un AVL con los N registros del archivo utilizando la ip como dato del nodo.
- Muestra los dos árboles construidos usando recorridos Preorden e Inorden. 
- Prueba borrar (1 nodo hoja, 1 nodo con 1 hijo y 1 nodo con dos hijos) en el ABB utilizando algunos de los datos insertados.
*/
#include <iostream>
#include <string>
#include <fstream>
#include "TreeAVL.h"
#include "TreeABB.h"
using namespace std;

int ip(string texto){
  /* 
  Función que extrae la IP de un texto
  Input: Un valor string 
  Output: Un valor entero 
  */
  int data;
  int j = 1;
  char separador = ' ';
  string iP;
  for (size_t p = 0, q = 0; p != texto.npos; p = q)
  {
    if (j < 4)
    {
        texto.substr(p + (p != 0), (q = texto.find(separador, p + 1)) - p - (p != 0));
    }
    else if (j == 4) {
        iP = texto.substr(p + (p != 0), (q = texto.find(separador, p + 1)) - p - (p != 0));
        break;
    }
    j++;
  }

  j = 1;
  separador = '.';
  size_t p = 0, q = 0;
  data = atoi((iP.substr(p + (p != 0), (q = iP.find(separador, p + 1)) - p - (p != 0))).c_str());
  return data;
}

TreeABB readingABB(int n) { 
  /*
  Función que lee los datos de un archivo de texto y los covertirá en una estructura arbol ABB y una estructura AVL. 
  Input: Un archivo de texto
  Output: Un objeto tipo TreeABB
  */
  TreeABB temp_ABB;
  string line;
  ifstream file;

  file.open("bitacora.txt",ios::in);

  if(file.fail()){ 
    std::cout << "readingABB[FALSE]: Error de lectura...";
    exit(1);
  }
  for(int i = 1; i <= n; i++){  
    getline(file,line); 
    temp_ABB.insert(ip(line), line);
  }
  return temp_ABB;
  file.close();
}


TreeAVL readingAVL(int n) { 
  /*
  Función que lee los datos de un archivo de texto y los covertirá en una estructura arbol ABB y una estructura AVL. 
  Input: Un archivo de texto
  Output: Un objeto tipo TreeABB
  */
  TreeAVL temp_AVL;
  string line;
  ifstream file;
  bool bo;

  file.open("bitacora.txt",ios::in);

  if(file.fail()){ 
    std::cout << "readingABB[FALSE]: Error de lectura...";
    exit(1);
  }

  for(int i = 1; i <= n; i++){
    bo = false;
    getline(file,line); 
    
    temp_AVL.setRoot(temp_AVL.insertAVL(temp_AVL.getRoot(), ip(line), bo, line)); 

  }
  return temp_AVL;
  file.close();
}

int main() {
  TreeABB a;
  TreeAVL b;
  int n;

  cout << "\nDigite cantidad de registros ";
  cout << "\n(Recomiendo 10 para poder validar casos de pruebas)\nn: ";
  cin >> n; 

  if(n>0){
    
    cout << "\nARBOL ABB" << endl;
    a = readingABB(n);
    cout << "\nAntes de borrar nodos.\n";
    cout << "\n\nPre orden\n\n"; a.pre_order(a.getRoot());
    cout << "\n\nEn orden\n\n"; a.in_order(a.getRoot());
    a.removed(84); // Hoja 
    a.removed(311); // Con un nodo hijo
    a.removed(423); // Nodo con dos nodos hijos, y es raiz. 
    cout << "\nDespues de borrar nodos.\n";
    cout << "\n\nPre orden\n\n"; a.pre_order(a.getRoot());
    cout << "\n\nEn orden\n\n"; a.in_order(a.getRoot());
    
  
    cout << "\n\n\nARBOL AVL" << endl;
    b = readingAVL(n);
    cout << "\n\nPre orden\n\n"; b.pre_order(b.getRoot());
    cout << "\n\nEn orden\n\n"; b.in_order(b.getRoot());
    
  }
  else{
    cout << "\nEl numero tiene que ser positivo y diferente de cero.\n";
  }
}