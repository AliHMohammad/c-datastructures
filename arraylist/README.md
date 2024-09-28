# Arraylist - Ali Mohammad

Tested on:
Windows 11

## Structure

### `ArrayList`
The `ArrayList` structure holds the following members:
- `int* data`: A pointer to the array of integers.
- `int capacity`: The current capacity of the array.
- `int size`: The current number of elements in the array.

## Functions

### `ArrayList* arraylist()`
Creates and initializes an ArrayList. Allocates memory for the structure and initial array. Returns a pointer to the newly created ArrayList.

### `void add(ArrayList* list, int value)`
Adds a new integer `value` to the end of the list. If the list is full, it expands the capacity by doubling it.

### `int get(ArrayList* list, int index)`
Retrieves the integer value at the specified `index`. Returns -1 and prints an error message if the index is out of bounds.

### `int size(ArrayList* list)`
Returns the current size (number of elements) of the list.

### `void clear(ArrayList* list)`
Clears all elements from the list and resets the list to its initial state with the default capacity.

### `void print_list(ArrayList list)`
Prints the current capacity, size, and all elements in the list.

### `void remove_last(ArrayList* list)`
Removes the last element from the list. If the size is reduced to half of the capacity, it reduces the capacity as well.

### `void set(ArrayList* list, int index, int value)`
Sets the value at the specified `index` to `value`. Prints an error message if the index is out of bounds.

### `void remove_index(ArrayList* list, int index)`
Removes the element at the specified `index`. Shifts elements to the left to fill the gap. Reduces capacity if the size is the half of the capacity.

### `void insert_index(ArrayList* list, int index, int value)`
Inserts `value` at the specified `index`, shifting subsequent elements to the right. Expands capacity if the the arraylist size is equal. Prints an error message if the index is out of bounds.

### `void expand_capacity(ArrayList* list)`
Doubles the current capacity of the list when the maximum size is reached. Allocates a new array and copies existing data.

### `void reduce_capacity(ArrayList* list)`
Halves the current capacity of the list if the size is half of the current capacity. Allocates a new array and copies existing data.



### How to run:

Windows: 
```bash
source ./run.sh
```

OSX:
```bash
source ./run_os.sh
```
