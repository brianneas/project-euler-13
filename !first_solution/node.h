#include <iostream>

class Node {
public:
   int data;
   Node* next;
   Node() : data(0), next(NULL) { } // Default Constructor
   Node(int num) : data(num), next(NULL) { } // Overloaded Constructor
};

void add_tail(Node*& head, int num);
void add_head(Node*& head, int num);
void del(Node*& head, int target);