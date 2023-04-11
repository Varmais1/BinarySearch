#include <iostream>
#include "tree.h"

using namespace std;

 //makes the command lowercase
void singlelowercase(char sentence[]);

int main() {
  char command[10];
  int nData;
  tree btree;
  while(true) {
    cout << "Type in add, delete, search, print, or quit." << endl;
    cin >> command;
    singlelowercase(command);
    if(strcmp(command, "quit") == 0) {
      btree.deleteAll(btree.getTop());
      return 0;
    }
    else if(strcmp(command, "add") == 0) {
      cout << "What number do you want to add?" << endl;
      cin >> nData;
      node* toAdd = new node(nData);
      btree.add(btree.getTop(),toAdd);
    }
    else if(strcmp(command, "print") == 0) {
      btree.print(btree.getTop(),0);
    }
    else if(strcmp(command, "delete") == 0) {
      cout << "Which number do you wish to delete?" << endl;
      cin >> nData;
      btree.remove(btree.getTop(), NULL, nData);
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
