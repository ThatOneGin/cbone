# Examples

this folder show some examples on how to use the library's functions
in both ways: the one that leaks some memory and the one that try to free all respective mallocs

## files

  - [build.c](./build.c) - Shows very basic functions and macros (overview).
  - [dir.c](./dir.c) - Shows functions to manipulate directories.
  - [sb.c](./sb.c) - String builders example

# How to use

## Dynamic arrays

**customizable macros**

- ```DA_DEFAULT_CAP```: minimum capacity for arrays

- ```DA_ASSERT```: assertion function used in errors

**function macros**

- ```DA_FREE```: free a dynamic array.

- ```DA_PUSH```: push an element to the front of an array.

- ```DA_POP```: remove an element on the front of the array.

- ```DA_PUSH_AT```: push an element at position (adjust others to fit).

- ```DA_POP_AT```: remove an element at position (adjust others to fill).

- ```DA_GET```: gets an element at given position, if the position is greater
than the size, it will give the last element. Otherwise if it underflows the size, the first.

## Declare dynamic arrays

```c
typedef struct {
  void *items; // array's content.
  size_t size; // indicates the number of used slots + 1 of the pointer.
  size_t capacity; // the maximum size of the array.
} MyCoolArray;
```

Note: *Any* struct with these 3 defined fields (items, size and capacity) can be used with these macros
and they also can have more fields as macros don't really care about that.