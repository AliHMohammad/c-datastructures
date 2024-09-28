#ifndef LINKLIST_H
#define LINKLIST_H

typedef struct Node {
    struct Node* nextNode;
    struct Node* prevNode;
    int data;
} Node;

typedef struct LinkedList {
    struct Node* head; // first node
    struct Node* tail; // last node
} LinkedList;


// det skal være muligt både at tilføje, fjerne, indsætte og ombytte nodes i listen.
LinkedList* linkedlist();
Node *node();
void add_first(LinkedList* list, int value);
void add_last(LinkedList* list, int value);
void remove_first(LinkedList* list);
void remove_last(LinkedList* list);

int get(LinkedList* list, int index);
int size(LinkedList* list);
void clear(LinkedList* list);
void print_list(LinkedList* list);
void set(LinkedList* list, int index, int value);
void remove_index(LinkedList* list, int index);
void add_index(LinkedList* list, int index, int value);

#endif // LINKLIST_H
