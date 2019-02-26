// Name: Brian Neas
// WSU ID: C282H554
// Assignment: 3

#include "node.h"
#include <iostream>

void addTail(Node*& head, int num) {
   // When the linked list is empty
   if (head == NULL) {
      head = new Node(num); // creates the first node
   } else {
      Node* temp = head;

      // Will iterate until it finds the LAST NODE which will have a null
      // pointer as it's "next" value
      while (temp->next != NULL) {
         temp = temp->next;
      }

      temp->next = new Node(num); // add the node
   }
}

void addHead(Node*& head, int num) {
   // make a copy of head
   Node* temp = head;

   // create a new node and assign to the head
   head = new Node(num);

   // tak care of the address field of new node
   head->next = temp;
}

void del(Node*& head, int target) {
   if (!head) {
      return; // when the linked list is empty
   }

   // create two pointers to keep track of the previous and current nodes
   Node* prev = NULL;
   Node* curr = head;

   // at the end of this loop, either you go over the entire linked list without
   // finding the target, or your curr pointer is pointing at the target
   while (curr != NULL && curr->data != target) {
      prev = curr;
      curr = curr->next;
   }

   // if curr == NULL, then it was not found
   if (curr == NULL) {
      return;
   }

   // delete the node pointed by the curr
   prev->next = curr->next;
   delete curr;
}