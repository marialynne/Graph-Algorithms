#pragma once
#include <iostream>
#include <string>
#include "Line.h"
using namespace std;

class NodeAVL
{
private:
  Line *data;
  int fe;
  NodeAVL *left;
  NodeAVL *right;

public:
  // defualt
  NodeAVL();
  virtual ~NodeAVL();
  // new constructor
  NodeAVL(Line *, int, NodeAVL *, NodeAVL *, string);

  // getters
  int getData();
  int getFe();
  NodeAVL *getLeft();
  NodeAVL *getRight();

  // setters
  void setData(int);
  void setFe(int);
  void setLeft(NodeAVL *);
  void setRight(NodeAVL *);
};
