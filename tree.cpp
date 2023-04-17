#include "tree.h"
/* Name: Ishaan Varma
   Date: 4/11/2023
   Purpose: Where all tree functions are implemented
 */

using namespace std;

//constructors
tree::tree() {
  top = NULL;
}

tree::tree(node* nTop) {
  top = nTop;
}


//deletes all nodes in a tree
void tree::deleteAll(node* nTop) {
  if(nTop != NULL) {
    deleteAll(nTop->getLeft());
    deleteAll(nTop->getRight());
    nTop->setLeft(NULL);
    nTop->setRight(NULL);
    delete nTop;
  }
}

//adds nodes to the tree
void tree::add(node* current, node* toAdd) {
  //if current is NULL, add to the top
  if(current == NULL) {
    top = toAdd;
    return;
  }

  //if the data that needs to be added is less than the current data
  if(toAdd->getData() < current->getData()) {
    //if the left is null, add the data to the left of current
    if(current->getLeft() == NULL) {
      current->setLeft(toAdd);
    }
    //if the data isn't null, do this function again with the left
    else {
      add(current->getLeft(), toAdd);
    }
  }
  //if the data that needs to be added is equal to the current data
  else if(toAdd->getData() == current->getData()) {
    //set the left of add to current's current left
    toAdd->setLeft(current->getLeft());
    //set current's left the data to be added
    current->setLeft(toAdd);
  }
  //if the data is to be added is more than the current data
  else {
    //if the right is NULL, add the data to the right
    if(current->getRight() == NULL) {
      current->setRight(toAdd);
    }
    //otherwise, do the function again with current's right
    else {
      add(current->getRight(), toAdd);
    }
  }
  
}

//prints out the trees
void tree::print(node* nTop, int depth) {
  //if the tree is empty, say the tree is empty
  if(top == NULL) {
    cout << "The tree is empty." << endl;
    return;
  }

  //if the left isn't NULL, do this function for the left
  if(nTop->getLeft() != NULL) {
    print(nTop->getLeft(), depth + 1);
  }

  //print out the appropriate amount of spaces
  for(int i = 0; i < depth; i++) {
    cout << "\t";
  }
  //output the data
  cout << nTop->getData() << endl;

  //if the right isn't NULL, do this function for the right
  if(nTop->getRight() != NULL) {
    print(nTop->getRight(), depth + 1);
  }
}


//revmoes a node from the data
void tree::remove(node* current, node* previous, int gone) {
  //stores whether the node is the top node
  bool isTop;
  //if this is the node to be deleted
  if(gone == current->getData()) {
    //is it the top node? isTop stores that
    isTop = current==top;
    //if the current node doesn't have any children
    if(current->getLeft() == NULL && current->getRight() == NULL) {
      //if its not the top
      if(!isTop) {
	//if the data is less than the previous, set the previous' left to null, and delete the node
	if(gone <= previous->getData()) {
	  previous->setLeft(NULL);
	  delete current;
	}
	//if the data is greater, set the previous's right to null, and delete the node
	else {
	  previous->setRight(NULL);
	  delete current;
	}
      }
      //if it the top, set top to null, and delete the node
      else {
	top = NULL;
	delete current;
      }
    }
    //if the left is null
    else if(current->getLeft() == NULL) {
      //if its not the top
      if(!isTop) {
	//if the data is less than the previous'
	if(gone <= previous->getData()) {
	  //set the previous' left to the current's right
	  previous->setLeft(current->getRight());
	}
	//otherwise, the the previous' right to the current's right
	else {
	  previous->setRight(current->getRight());
	}
	//the the current's right to null
	current->setRight(NULL);
	//delete the current
	delete current;
      }
      //if it is the top, and its left is null
      else {
	//top becomes the right
	top = top->getRight();
	//set current's right to null to not delete the right
	current->setRight(NULL);
	//delete the current
	delete current;
      }
    }
    //if the currents right is null, do the same thing as if its left was null, just switching most rights with left
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
    //if the node has 2 children
    else {
      //and its not the top
      if(!isTop) {
	//node* which will get swapped
	node* swap = current->getRight();
	//what will be the new bottom
	node* nBottom = swap;
	//while the swap isn't the smallest node bigger than the current node, keep on getting smaller
	while(swap->getLeft() != NULL) {
	  nBottom = swap;
	  swap = swap->getLeft();
	}
	//set the new bottom's left to NULL
	nBottom->setLeft(NULL);
	//set the new bottom's right to the old bottoms right
	nBottom->setRight(swap->getRight());
	//of the previous isn't null
	if(previous != NULL) {
	  //of the previous' data is larger or equal to than the current data
	  if(gone <= previous->getData()) {
	    //set the previous' left to swap
	    previous->setLeft(swap);
	  }
	  else {
	    //otherwise set the right to the swap
	    previous->setRight(swap);
	  }
	}
	//set swap's left to current left
	swap->setLeft(current->getLeft());
	//if swap isn't current's right, set swaps right to currents right
	if(swap != current->getRight()) {
	  swap->setRight(current->getRight());
	}
	//set currents left and right to null
	current->setLeft(NULL);
	current->setRight(NULL);
	//delete the current
	delete current;
      }
      //if the top has 2 children and needs to be deleted
      else {
	//swap and bottom
	node*swap = current->getRight();
	node* nBottom = current;
	//while the swap isn't the smallest number bigger than the top, make swap the next smallest number
	while(swap->getLeft() != NULL) {
	  nBottom = swap;
	  swap = swap->getLeft();
	}
	//if the new bottom is the top
	if(nBottom == top) {
	  //set the new bottom to null
	  nBottom = NULL;
	  //set current's right to null
	  current->setRight(NULL);
	  //set swaps left to currents left
	  swap->setLeft(current->getLeft());
	  //set current's left to null
	  current->setLeft(NULL);
	  //make top swap
	  top = swap;
	  //delete current
	  delete current;
	  //filler line for debugging
	  bool filler = true;;
	}
	//if the new bottom isn't the top
	else {
	  //set the new bottom's left to null
	  nBottom->setLeft(NULL);
	  //set the new bottoms right to swap's right
	  nBottom->setRight(swap->getRight());
	  //set swaps left to the current left
	  swap->setLeft(current->getLeft());
	  //set swaps right to currents right
	  swap->setRight(current->getRight());
	  //set top to swap
	  top = swap;
	  //set currents left and right to null
	  current->setLeft(NULL);
	  current->setRight(NULL);
	  //delete current
	  delete current;
	  //debugging line
	  bool filler = true;
	}
      }
    }
  }
  //if the data is less than the current node, do this function again with the left
  else if(gone < current->getData()) {
    remove(current->getLeft(), current, gone);
  }
  //otherwise, do this with the right
  else {
    remove(current->getRight(), current, gone);
  }
}

//returns the top of the tree
node* tree::getTop() {
  return top;
}

//finds if a number is in a tree, if it isn't, return false, if it is, return true, if the data is less than the current, do this function with the left, if the data is more than current, do this with the right
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
