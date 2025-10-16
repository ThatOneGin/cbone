# Examples

this folder show some examples on how to use the library's functionalities.

### Contents

  - [build](./build/) - Demonstrates how to use the library to build C files.
  - [dirs.c](./setup-directories/dirs.c) - Shows functions to manipulate directories.
  - [string-builder.c](./string-builder/string-builder.c) - String builders example
  - [list-files](./list-files/list-files.c) - How to use cbone_foreach_file_in macro.

# How to use

## Dynamic arrays

**customizable macros**

- ```CBONE_DA_DEFAULT_CAP```: minimum capacity for arrays

- ```CBONE_ASSERT```: assertion function used in errors

**function macros**

- ```CBONE_DA_FREE```: free a dynamic array.

- ```CBONE_DA_PUSH```: push an element to the front of an array.

- ```CBONE_DA_POP```: remove an element on the front of the array.

- ```CBONE_DA_PUSH_AT```: push an element at position (adjust others to fit).

- ```CBONE_DA_POP_AT```: remove an element at position (adjust others to fill).

- ```CBONE_DA_GET```: gets an element at given position, if the position is greater
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