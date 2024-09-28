#include <stdio.h>
#include <stdlib.h>
#include "arraylist.h"

#define START_SIZE 10

int main(int argc, char const *argv[])
{
    ArrayList* list = arraylist();
    
    add(list, 4);
    add(list, 55);
    add(list, 24);
    add(list, 65);
    int item = get(list, 4);
    print_list(*list);
    printf("value: %d\n", item);
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
    //TODO: Check.
}

int get(ArrayList* list, int index) {
    if ((list->size - 1) < index) {
        puts("Index out of bounds.");
        return -1;
        //TODO: Throw exception
    }

    return *(list->data + index);
}







void print_list(ArrayList list) {
    printf("Capacity: %d\n", list.capacity);
    printf("Size: %d\n", list.size);

    for (int i = 0; i < list.capacity; i++) {                     
        printf("Data[%d]: %d\n", i, *(list.data + i));
    }
}
