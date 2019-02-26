// Name: Brian Neas
// WSU ID: C282H554
// Assignment: 3

#include <iostream>
#include <fstream>
#include <sstream>
#include "node.h"

#define NUM_LENGTH 50

using namespace std;

void import(string* arr, int size) {
   ifstream file;
   file.open("nums.txt");

   if (!file) {
     cout << "nums.txt could not be opened." << endl;
   }

   for (int i = 0; i < size; i++) {
      string tempS = "";
      getline(file, tempS);
      reverse(tempS.begin(), tempS.end());
      arr[i] = tempS;
   }

   file.close();
}

void addNode(Node*& head, string num) {
   int remainder = 0;
   Node* temp = head;

   // stream the string to a streamstring object for easier handling
   stringstream ss;
   ss << num;

   for (int i = 0; i < 50; i++) {
      // create an empty char, and stream the first char of the ss to that char
      // then convert that char to an int
      char digitC;
      ss.get(digitC);
      int digit = digitC - '0';

      // add the remainder, node data, and streamed digit to get the final
      // value for that place in the list
      int nodeData = temp->data; // gets digit value from node
      remainder += nodeData;
      remainder += digit;

      // use modulus to get the final digit of the remainder which is the
      // digit you want to write to your node as your new digit
      temp->data = remainder % 10;
      remainder /= 10; // use integer division to elminate the last digit

      if (i != 49) {
         temp = temp->next; // set temp to the next node in line
      }
   }

   while (remainder != 0) {
      if (temp->next == NULL) {
         add_tail(head, (remainder % 10));
         remainder /= 10;
         temp = temp->next;
      } else {
         int nodeData = temp->data;
         remainder += nodeData;
         temp->data = remainder % 10;
         remainder /= 10;
         temp = temp->next;
      }
   }
}

int main() {
   int size = 100;
   string nums[100];

   // import all of the numbers as strings (backwards)
   import(nums, size);

   for (int i = 0; i < size; i++) {
      cout << i << ": " << nums[i] << endl;
   }


   // Create a new head with (50) values
   Node* head = NULL;

   // Initialize all values of the nodes to 0
   for (int i = 1; i <= 50; i++) {
      add_tail(head, 0);
   }

   // Add each number in the array
   for (int i = 0; i < 100; i++) {
      addNode(head, nums[i]);
   }


   Node* temp = head;

   stringstream ss;

   while (temp) {
      ss << temp->data;
      temp = temp->next;
   }

   cout << endl;

   return 0;
}