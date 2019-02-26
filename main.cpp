// Name: Brian Neas
// WSU ID: C282H554
// Assignment: 3

#include <iostream>
#include <fstream>
#include <sstream>
#include "node.h"

using namespace std;

// imports strings from a file and loads them into an array of numbers stored
// as strings
void import(string* nums, int size) {
   // create file object
   ifstream file;
   file.open("nums.txt");

   if (!file) {
     cout << "nums.txt could not be opened." << endl;
   }

   // get each line from the file, and reverse it and store in the array
   for (int i = 0; i < size; i++) {
      string tempS = "";
      getline(file, tempS);
      reverse(tempS.begin(), tempS.end());
      nums[i] = tempS;
   }

   file.close();
}

// converts a string to integer values and adds it to a linked list
void addToList(Node*& head, string num) {
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
      // If the last node has a null pointer, add another tail to the list
      if (temp->next == NULL) {
         // the value should be the remainder % 10, because you are done
         // summing numbers
         addTail(head, (remainder % 10));
         remainder /= 10; // integer division of remainder
         temp = temp->next;
      } else {
         temp = temp->next; // get the next node
         int nodeData = temp->data; // get the node data, as above
         remainder += nodeData; // add it to the remainder, as above
         temp->data = remainder % 10; // do modulus, as above
         remainder /= 10; // integer division, as above
      }
   }
}

// prints the first 10 digit of the linked list, and also prints the entire
// list
void printList(Node* head) {
   Node* temp = head; // create a temp pointer to the head (to be iterated over)

   // create a stringstream to stream the values from the Nodes to
   stringstream ss;

   // stream each of the node data to the streamstring
   while (temp) {
      ss << temp->data;
      temp = temp->next;
   }

   // convert the ss to a string and then reverse it so it'll display correctly
   string ans = ss.str();
   reverse(ans.begin(), ans.end());

   // print per homework requirements
   cout << "First 10 Digits of Final Summation: ";

   for (int i = 0; i < 10; i++) {
      cout << ans[i];
   }

   cout << endl;

   cout << "Final Summation: " << ans << endl;
}

int main() {
   int size = 100;
   string nums[100];

   // import all of the numbers as strings (backwards)
   import(nums, size);

   // Create a new head with (50) values
   Node* head = NULL;

   // Initialize all values of the nodes to 0
   for (int i = 1; i <= 50; i++) {
      addTail(head, 0);
   }

   // Add each number in the array
   for (int i = 0; i < 100; i++) {
      addToList(head, nums[i]);
   }

   // print the required answers
   printList(head);

   return 0;
}