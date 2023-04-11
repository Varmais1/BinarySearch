#include "node.h"

class tree {
 public:
  tree();
  tree(node* nTop);
  node* getTop();
  void add(node* current, node* toAdd);
  void print(node* nTop, int depth);
  void remove(node* current, node* previous, int gone);
  void search(node* find);
  void deleteAll(node* nTop);
 private:
  node* top;
};
