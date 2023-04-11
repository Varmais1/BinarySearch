#include "node.h"
/* Name: Ishaan Varma
   Date: 4/11/2023
   Purpose: Tree class header file
 */

class tree {
 public:
  //constructors
  tree();
  tree(node* nTop);
  //getters and setters
  node* getTop();
  void add(node* current, node* toAdd);
  void print(node* nTop, int depth);
  void remove(node* current, node* previous, int gone);
  bool search(int find, node* current);
  void deleteAll(node* nTop);
 private:
  node* top;
};
