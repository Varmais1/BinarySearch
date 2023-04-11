#include "node.h"

node::node() {
  data = 0;
  left = NULL;
  right = NULL;
}

node::node(int nData) {
  data = nData;
  left = NULL;
  right = NULL;
}

node::node(int nData, node* nLeft, node* nRight) {
  data = nData;
  left = nLeft;
  right = nRight;
}


void node::setData(int nData) {
  data = nData;
}

void node::setRight(node* nRight) {
  right = nRight;
}

void node::setLeft(node* nLeft) {
  left = nLeft;
}

int node::getData() {
  return data;
}

node* node::getLeft() {
  return left;
}

node* node::getRight() {
  return right;
}

node::~node() {
  if(left != NULL) {
    delete left;
  }
  if(right != NULL) {
    delete right;
  }
}
