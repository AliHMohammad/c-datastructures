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

LinkedList* linkedlist();
Node *node();
void add_first(LinkedList* list, int value);
void add_last(LinkedList* list, int value);
void remove_first(LinkedList* list);
void remove_last(LinkedList* list);
void add_index(LinkedList* list, unsigned int index, int value);
void remove_index(LinkedList* list, int index);
void swap(LinkedList *list, unsigned int indexOne, unsigned int indexTwo);
void print_list(LinkedList* list);

#endif // LINKLIST_H
