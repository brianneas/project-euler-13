// Name: Brian Neas
// WSU ID: C282H554
// Assignment: 3

#include <iostream>
#include <fstream>
#include "node.h"

#define NUM_LENGTH 50

using namespace std;

void import(Node** arr, int size) {
   ifstream file;
   file.open("nums.txt");

   if (!file) {
     cout << "nums.txt could not be opened." << endl;
   }

   for (int i = 0; i < size; i++) {
      for (int j = 0; j < NUM_LENGTH; j++) {
         char nextChar = '0';
         file.get(nextChar);

         int newInt = 0;
         newInt = nextChar - '0';
         add_head(arr[i], newInt);
      }

      file.ignore();
   }

   file.close();
}

void addNodes(Node** arr, int size, Node*& finalList) {
   int remainder = 0;

   // the place is the i - 1, 10, 100, 1000
   for (int i = 0; i < NUM_LENGTH; i++) { // TODO: CHANGE 1 TO NUM_LENGTH

      // for each place, need to add up the whole column
      for (int j = 0; j < size; j++) {
         Node* temp = arr[j]; // each new number

         // traverse through the linked list to the place holding the value
         // you need to add
         for (int k = 0; k < i; k++) {
            temp = temp->next;
         }

         // add that value to the remainder
         remainder += temp->data;
      }

      // remainder will now be the total of the column plus the remainder
      // from the last column addition

      // add the last digit in the remainder as the final value that goes
      // in the final list
      // NOTE: using add head means the finalList will be stored with the
      // largest digit first, and the smallest digit last
      cout << "Remainder: " << remainder << ", Final Digit: " << remainder % 10
         << endl;
      cout << i << endl;
      int finalDigit = remainder % 10;
      add_head(finalList, finalDigit);

      // do integer division on the remainder to pop off the last digit, since
      // it has already been added to the final list
      remainder /= 10;
   }

   // At this point, all columns will have been added, and the remainder
   // is the additional numbers that need to be added to the final value
   while (remainder != 0) {
      cout << "Remainder: " << remainder << ", Final Digit: " << remainder % 10
         << endl;
      add_head(finalList, (remainder % 10));
      remainder /= 10;
   }
}

int main() {
   int size = 100;
   Node* arr[100];

   for (int i = 0; i < size; i++) {
      Node* newHead = NULL;
      arr[i] = newHead;
   }

   import(arr, size);

   Node* finalList = NULL;

   addNodes(arr, size, finalList);

   Node* temp = finalList;

   while (temp) {
      cout << temp->data;
      temp = temp->next;
   }

   cout << endl;

   return 0;
}