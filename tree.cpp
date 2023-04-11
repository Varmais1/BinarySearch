#include "tree.h"

using namespace std;

tree::tree() {
  top = NULL;
}

tree::tree(node* nTop) {
  top = nTop;
}


void tree::deleteAll(node* nTop) {
  if(nTop != NULL) {
    deleteAll(nTop->getLeft());
    deleteAll(nTop->getRight());
    nTop->setLeft(NULL);
    nTop->setRight(NULL);
    delete nTop;
  }
}

void tree::add(node* current, node* toAdd) {
  if(current == NULL) {
    top = toAdd;
    return;
  }
  
  if(toAdd->getData() < current->getData()) {
    if(current->getLeft() == NULL) {
      current->setLeft(toAdd);
    }
    else {
      add(current->getLeft(), toAdd);
    }
  }
  else if(toAdd->getData() == current->getData()) {
    toAdd->setLeft(current->getLeft());
    current->setLeft(toAdd);
  }
  else {
    if(current->getRight() == NULL) {
      current->setRight(toAdd);
    }
    else {
      add(current->getRight(), toAdd);
    }
  }
  
}

void tree::print(node* nTop, int depth) {
  if(top == NULL) {
    cout << "The tree is empty." << endl;
    return;
  }
  
  if(nTop->getLeft() != NULL) {
    print(nTop->getLeft(), depth + 1);
  }
  
  for(int i = 0; i < depth; i++) {
    cout << "\t";
  }
  cout << nTop->getData() << endl;
  
  if(nTop->getRight() != NULL) {
    print(nTop->getRight(), depth + 1);
  }
}

void tree::remove(node* current, node* previous, int gone) {
  bool isTop;
  if(gone == current->getData()) {
    isTop = current==top;
    if(current->getLeft() == NULL && current->getRight() == NULL) {
      if(!isTop) {
	if(gone < previous->getData()) {
	  previous->setLeft(NULL);
	  delete current;
	}
	else {
	  previous->setRight(NULL);
	  delete current;
	}
      }
      else {
	top = NULL;
	delete current;
      }
    }
    else if(current->getLeft() == NULL) {
      if(!isTop) {
	if(gone < previous->getData()) {
	  previous->setLeft(current->getRight());
	}
	else {
	  previous->setRight(current->getRight());
	}
	current->setRight(NULL);
	delete current;
      }
      else {
	top = top->getRight();
	current->setRight(NULL);
	delete current;
      }
    }
    else if(current->getRight() == NULL) {
      if(!isTop) {
	if(gone < previous->getData()) {
	  previous->setLeft(current->getLeft());
	}
	else {
	  previous->setRight(current->getLeft());
	}
	current->setLeft(NULL);
	delete current;
      }
      else {
	top = top->getLeft();
	current->setLeft(NULL);
	delete current;
      }
    }
    else {
      if(!isTop) {
	node* swap = current->getRight();
	node* nBottom = swap;
	while(swap->getLeft() != NULL) {
	  nBottom = swap;
	  swap = swap->getLeft();
	}
	nBottom->setLeft(NULL);
	nBottom->setRight(swap->getRight());
	if(previous != NULL) {
	  if(gone < previous->getData()) {
	    previous->setLeft(swap);
	  }
	  else {
	    previous->setRight(swap);
	  }
	}
	swap->setLeft(current->getLeft());
	if(swap != current->getRight()) {
	  swap->setRight(current->getRight());
	}
	current->setLeft(NULL);
	current->setRight(NULL);
	delete current;
      }
      else {
	node*swap = current->getRight();
	node* nBottom = current;
	while(swap->getLeft() != NULL) {
	  nBottom = swap;
	  swap = swap->getLeft();
	}
	if(nBottom == top) {
	  nBottom = NULL;
	  current->setRight(NULL);
	  swap->setLeft(current->getLeft());
	  current->setLeft(NULL);
	  top = swap;
	  delete current;
	  bool filler = true;;
	}
	else {
	  nBottom->setLeft(NULL);
	  nBottom->setRight(swap->getRight());
	  swap->setLeft(current->getLeft());
	  swap->setRight(current->getRight());
	  top = swap;
	  current->setLeft(NULL);
	  current->setRight(NULL);
	  delete current;
	  bool filler = true;
	}
      }
    }
  }
  else if(gone < current->getData()) {
    remove(current->getLeft(), current, gone);
  }
  else {
    remove(current->getRight(), current, gone);
  }
}

node* tree::getTop() {
  return top;
}

bool tree::search(int find, node* current) {
  if(current == NULL) {
    return false;
  }
  else if(find == current->getData()) {
    return true;
  }
  else if(find < current->getData()) {
    return search(find, current->getLeft());
  }
  else {
    return search(find, current->getRight());
  }
  return false;
}
