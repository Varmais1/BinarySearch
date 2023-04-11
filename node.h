#include <iostream>
#include <cstring>

class node {
 public:
  node();
  node(int nData);
  node(int nData, node* nLeft, node* nRight);
  ~node();
  void setData(int nData);
  void setRight(node* nRight);
  void setLeft(node* nLeft);
  int getData();
  node* getLeft();
  node* getRight();

 private:
  int data;
  node* left;
  node* right;
};
