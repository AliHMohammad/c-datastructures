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
void list_remove(ArrayList* list);
void clear(ArrayList* list);
void set(ArrayList* list, int index, int value);
void remove_index(ArrayList* list, int index);
void insert_index(ArrayList* list, int index, int value);
void print_list(ArrayList list);

#endif // ARRAYLIST_H
