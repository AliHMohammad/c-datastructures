#include <stdio.h>
#include <stdlib.h>
#include "arraylist.h"

#define START_SIZE 10

int main(int argc, char const *argv[])
{
    ArrayList* list = arraylist();

    add(list, 77);
    add(list, 12134);
    add(list, 3424);
    add(list, 62);

    set(list, 2, 10);
    print_list(*list);

    return 0;
}


ArrayList* arraylist() {
    ArrayList* myArr = (ArrayList*) malloc(sizeof(ArrayList));
    myArr->data = (int*) malloc(START_SIZE * sizeof(int));
    myArr->size = 0;
    myArr->capacity = START_SIZE;

    return myArr;
}

void add(ArrayList* list, int value) {
    *(list->data + list->size) = value;
    list->size += 1;
    //TODO: Check to expand capacity
}

int get(ArrayList* list, int index) {
    if ((list->size - 1) < index) {
        puts("Index out of bounds.");
        return -1;
        //TODO: Throw exception
    }

    return *(list->data + index);
}

int size(ArrayList* list) {
    return list->size;
}

void clear(ArrayList* list) {
    free(list->data);
    list->data = (int*) malloc(START_SIZE * sizeof(int));
    list->size = 0;
    list->capacity = START_SIZE;
}

void remove_last(ArrayList* list) {
    if (list->size == 0) {
        return;
    }

    int lastIndex = list->size - 1;

    *(list->data + lastIndex) = '\0';
    list->size -= 1;

    //TODO: Check to minimize capacity
}

void set(ArrayList* list, int index, int value) {
    if ((list->size - 1) < index) {
        puts("Index out of bounds.");
        return;
        //TODO: Throw exception
    }

    *(list->data + index) = value;
}


void print_list(ArrayList list) {
    printf("Capacity: %d\n", list.capacity);
    printf("Size: %d\n", list.size);

    for (int i = 0; i < list.capacity; i++) {                     
        printf("Data[%d]: %d\n", i, *(list.data + i));
    }
}
