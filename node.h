// Name: Brian Neas
// WSU ID: C282H554
// Assignment: 3

#include <iostream>

class Node {
public:
   int data; // holds integer data for the node
   Node* next; // pointer to the next node in the list (can be NULL if ground)
   Node() : data(0), next(NULL) { } // Default Constructor
   Node(int num) : data(num), next(NULL) { } // Overloaded Constructor
};

void addTail(Node*& head, int num);
void addHead(Node*& head, int num);
void del(Node*& head, int target);