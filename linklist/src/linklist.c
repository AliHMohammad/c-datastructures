#include <stdio.h>
#include <stdlib.h>
#include "linklist.h"



// typedef struct Node {
//     Node* nextNode;
//     Node* prevNode;
//     int data;
// } Node;

// typedef struct LinkedList {
//     Node* head; // first node
//     Node* tail; // last node
// } LinkedList;



int main(int argc, char const *argv[])
{
    LinkedList* list = linkedlist();
    add_first(list, 10);
    print_list(list);
    add_first(list, 4);
    add_first(list, 567);
    print_list(list);
    add_last(list, 1345);
    print_list(list);
    remove_first(list);
    print_list(list);
    remove_last(list);
    print_list(list);

    return 0;
}

LinkedList* linkedlist() {
    LinkedList* list = malloc(sizeof(LinkedList));
    list->head = NULL;
    list->tail = NULL;

    return list;
}

Node* node() {
    Node* node = malloc(sizeof(Node));
    node->data = NULL;
    node->nextNode = NULL;
    node->prevNode = NULL;

    return node;
}

void add_first(LinkedList* list, int value) {
    Node* newNode = node();
    newNode->data = value;

    Node* prevList = list->head; 

    newNode->nextNode = prevList; 

    if (prevList != NULL) {
        prevList->prevNode = newNode;
    } else {
        list->tail = newNode;
    }

    list->head = newNode;
}

void add_last(LinkedList *list, int value) {
    Node* newNode = node();
    newNode->data = value;
    newNode->nextNode = NULL;

    Node* tailNode = list->tail;

    tailNode->nextNode = newNode;
    newNode->prevNode = tailNode;

    list->tail = newNode;
}

void remove_first(LinkedList* list) {
    Node* tempList = list->head->nextNode;
    tempList->prevNode = NULL;

    free(list->head);
    list->head = tempList;
}

void remove_last(LinkedList* list) {
    Node *lastNode = list->tail;
    lastNode->prevNode->nextNode = NULL;
    list->tail = lastNode->prevNode;

    free(lastNode);
}

void print_list(LinkedList* list) {
    printf("=========================\n");
    printf("Linked List Properties:\n");
    printf("Head Node: %p, Data: %d\n", (void*)list->head, list->head ? list->head->data : 0);
    printf("Tail Node: %p, Data: %d\n", (void*)list->tail, list->tail ? list->tail->data : 0);
    
    printf("Nodes in the list:\n");
    Node* current = list->head;
    while (current != NULL) {
        printf("Node Address: %p, Data: %d, Next Node: %p, Previous Node: %p\n",
               (void*)current, current->data, (void*)current->nextNode, (void*)current->prevNode);
        current = current->nextNode; // Move to the next node
    }
}
