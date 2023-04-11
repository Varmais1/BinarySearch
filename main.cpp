#include <iostream>
#include "tree.h"
/* Name: Ishaan Varma
   Date: 4/11/2023
   Purpose: Where the program is run
 */


using namespace std;

 //makes the command lowercase
void singlelowercase(char sentence[]);

//main
int main() {
  //stores commands
  char command[10];
  //stores data
  int nData;
  //the tree
  tree btree;
  //run
  while(true) {
    //get data
    cout << "Type in add, delete, search, print, or quit." << endl;
    cin >> command;
    singlelowercase(command);
    //if quit, delete the tree, and return 0
    if(strcmp(command, "quit") == 0) {
      btree.deleteAll(btree.getTop());
      return 0;
    }
    //if add, get the number to add, and call the add function
    else if(strcmp(command, "add") == 0) {
      cout << "What number do you want to add?" << endl;
      cin >> nData;
      node* toAdd = new node(nData);
      btree.add(btree.getTop(),toAdd);
    }
    //if print, call the tree print function
    else if(strcmp(command, "print") == 0) {
      btree.print(btree.getTop(),0);
    }
    //if delete, get the number to delete and call the tree delete function
    else if(strcmp(command, "delete") == 0) {
      cout << "Which number do you wish to delete?" << endl;
      cin >> nData;
      btree.remove(btree.getTop(), NULL, nData);
    }
    //if search, get the number to search for, and print the results
    else if(strcmp(command, "search") == 0) {
      cout << "Which number do you want to search for?" << endl;
      cin >> nData;
      bool isThere = btree.search(nData, btree.getTop());
      if(isThere) {
	cout << "That number is in the tree." << endl;
      }
      else {
	cout << "That number is not in the tree." << endl;
      }
    }
  }
  
  
}

void singlelowercase(char sentence[]) {
  //iterating variable
   int i = 0;
   //go through the char array
   while(true) {
     int charVal = (int) sentence[i];
     //if the letter is capital, make it lowercase using ASCII
     if(65<=charVal && charVal <= 90) {
       sentence[i] = (char)(charVal+32);
     }
     //if the character is the null character, 
     else if(sentence[i] == '\0') {
       break;
     }
     //increment the variable
     i++;
   }
}
