#ifndef ARRAYLIST_H
#define ARRAYLIST_H

typedef struct ArrayList {
    int* data;
    int capacity;
    int size;
} ArrayList;

ArrayList* arraylist();
void add(ArrayList* list, int value);
int get(ArrayList* list, int index);
int size(ArrayList* list);
void clear(ArrayList* list);
void print_list(ArrayList* list);
void remove_last(ArrayList* list);
void set(ArrayList* list, int index, int value);
void remove_index(ArrayList* list, int index);
void insert_index(ArrayList* list, int index, int value);

void expand_capacity(ArrayList* list);
void reduce_capacity(ArrayList *list);

#endif // ARRAYLIST_H
