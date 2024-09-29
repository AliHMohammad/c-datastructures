#include <stdio.h>
#include <stdlib.h>
#include "arraylist.h"

#define START_SIZE 5


int main(int argc, char const *argv[])
{
    ArrayList* list = arraylist();

    add(list, 77);
    add(list, 12134);
    add(list, 3424);
    print_list(list);
    add(list, 62);
    add(list, 232);
    add(list, 565);
    add(list, 11);
    add(list, 3578);
    add(list, 4);
    add(list, 68);
    print_list(list);
    add(list, 33);
    print_list(list);

    remove_last(list);
    remove_last(list);
    remove_last(list);

    print_list(list);

    return 0;
}


ArrayList* arraylist() {
    ArrayList* myArr = malloc(sizeof(ArrayList));
    myArr->data = (int*) malloc(START_SIZE * sizeof(int));
    myArr->size = 0;
    myArr->capacity = START_SIZE;

    return myArr;
}

void expand_capacity(ArrayList* list) {
    int *newArrData = malloc((list->capacity * 2) * sizeof(int));

    for (int i = 0; i < list->size; i++)
    {
        *(newArrData + i) = *(list->data + i);
    }

    free(list->data);
    list->data = newArrData;

    list->capacity *= 2;
}

void reduce_capacity(ArrayList* list) {
    if (list->capacity == START_SIZE) {
        return;
    }

    int *newArrData = malloc((list->capacity / 2) * sizeof(int));

    for (int i = 0; i < list->size; i++)
    {
        *(newArrData + i) = *(list->data + i);
    }

    free(list->data);
    list->data = newArrData;
    list->capacity /= 2;
}

void add(ArrayList* list, int value) {
    if (list->size == list->capacity){
        expand_capacity(list);
    }

    *(list->data + list->size) = value;
    list->size += 1;
    
}

int get(ArrayList* list, int index) {
    if ((list->size - 1) < index) {
        puts("Index out of bounds.");
        return -1;
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

    if (list->size == (list->capacity / 2)) {
        reduce_capacity(list);
    }
}

void set(ArrayList* list, int index, int value) {
    if ((list->size - 1) < index) {
        puts("Index out of bounds.");
        return;
    }

    *(list->data + index) = value;
}

void remove_index(ArrayList* list, int index) {
    if ((list->size - 1) < index) {
        puts("Index out of bounds.");
        return;
    }

    for (int i = index; i < (list->size - 1); i++)
    {
        *(list->data + i) = *(list->data + i + 1);
    }

    int lastIndex = list->size - 1;
    *(list->data + lastIndex) = '\0';
    list->size -= 1;

    if (list->size == (list->capacity / 2)) {
        reduce_capacity(list);
    }
}

void insert_index(ArrayList* list, int index, int value){
    if ((list->size - 1) < index) {
        puts("Index out of bounds.");
        return;
    }

    if (list->size == list->capacity){
        expand_capacity(list);
    }

    int tempSize = list->size - index;
    int *tempArr = malloc(tempSize * sizeof(int));

    for (int i = index, j = 0; i < list->size; i++, j++)
    {
        *(tempArr + j) = *(list->data + i);
    }

    *(list->data + index) = value;

    for (int i = index + 1, j = 0; j < tempSize; i++, j++)
    {
        *(list->data + i) = *(tempArr + j);
    }

    free(tempArr);
}


void print_list(ArrayList* list) {
    printf("====================\n");
    printf("Capacity: %d\n", list->capacity);
    printf("Size: %d\n", list->size);

    for (int i = 0; i < list->capacity; i++) {                     
        printf("Data[%d]: %d\n", i, *(list->data + i));
    }
}


