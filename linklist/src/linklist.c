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
    LinkedList* templist = linkedlist();
    templist->head = list->head;

    Node* newNode = node();
    newNode->data = value;

    list->head = newNode;
    newNode->nextNode = templist->head;

    free(templist);
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
