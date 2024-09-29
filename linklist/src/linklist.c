#include <stdio.h>
#include <stdlib.h>
#include "linklist.h"


int main(int argc, char const *argv[])
{
    LinkedList* list = linkedlist();
    add_last(list, 10);
    print_list(list);
    add_first(list, 4);
    add_first(list, 567);
    add_last(list, 1345);
    print_list(list);
    add_first(list, 754);
    add_last(list, 1222);
    add_first(list, 43);
    add_last(list, 1334);
    add_index(list, 2, 777);
    print_list(list);
    remove_index(list, 4);
    remove_last(list);
    print_list(list);
    swap(list, 1, 3);
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

    if (tailNode == NULL) {
        list->head = newNode;
    } else {
        tailNode->nextNode = newNode;
        newNode->prevNode = tailNode;
    }

    list->tail = newNode;
}

void add_index(LinkedList* list, unsigned int index, int value) {
    Node* newNode = node();
    newNode->data = value;

    if (index == 0) {
        add_first(list, value);
        return;
    }

    Node* node = list->head;
    for (int i = 0; i < index; i++)
    {
        node = node->nextNode;
        if (node == NULL) {
            add_last(list, value);
            return;
        }
    }

    Node* nodePrev = node->prevNode;

    newNode->prevNode = node->prevNode;
    nodePrev->nextNode = newNode;

    newNode->nextNode = node;
    node->prevNode = newNode;
}

void remove_index(LinkedList* list, int index) {
    if (index == 0) {
        remove_first(list);
        return;
    }

    Node* nodeToRemove = list->head;
    for (int i = 0; i < index; i++)
    {
        nodeToRemove = nodeToRemove->nextNode;
        if (nodeToRemove == NULL) {
            remove_last(list);
            return;
        }
    }

    Node *nodeBefore = nodeToRemove->prevNode;
    Node *nodeAfter = nodeToRemove->nextNode;

    nodeBefore->nextNode = nodeAfter;
    nodeAfter->prevNode = nodeBefore;

    free(nodeToRemove);
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

void swap(LinkedList *list, unsigned int indexOne, unsigned int indexTwo) {
    Node* firstNode = list->head;
    Node* secondNode = list->head;

    for (int i = 0; i < indexOne; i++)
    {
        if (firstNode->nextNode == NULL) {
            break;
        }

        firstNode = firstNode->nextNode;
    }

    for (int i = 0; i < indexTwo; i++)
    {
        if (secondNode->nextNode == NULL) {
            break;
        }

        secondNode = secondNode->nextNode;
    }

    // If indexOne and IndexTwo equal or both indexes are out of bounds, return
    if (firstNode == secondNode) {
        return;
    }

    Node* tempNode = node();
    tempNode->data = NULL;
    Node* prevNode;
    Node* nextNode;

    // Save firstNode information in tempNode
    tempNode->nextNode = firstNode->nextNode;
    tempNode->prevNode = firstNode->prevNode;

    // Save the previous node and the next node to the node to be replaced
    prevNode = secondNode->prevNode;
    nextNode = secondNode->nextNode;

    // Overwrite firstNode fields except data, with secondNode fields;
    // PrevNode and NextNode is set to firstNode
    firstNode->prevNode = secondNode->prevNode;
    prevNode->nextNode = firstNode;
    firstNode->nextNode = secondNode->nextNode;
    nextNode->prevNode = firstNode;

    // Save the previous node and the next node to the node to be replaced
    prevNode = tempNode->prevNode;
    nextNode = tempNode->nextNode;

    // Overwrite secondNode fields except data with tempNode (firstNode) fields
    // PrevNode and NextNode is set to secondNode
    secondNode->prevNode = tempNode->prevNode;
    prevNode->nextNode = secondNode;
    secondNode->nextNode = tempNode->nextNode;
    nextNode->prevNode = secondNode;

    // Free tempNode
    free(tempNode);
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
