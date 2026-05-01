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

- ```cbone_assert```: assertion function used in errors

- ```CBONE_STRIP_PREFIX```: remove the 'cbone_' prefix for library functions and macros

- ```CBONE_BE_QUIET```: tells cbone to not log commands

- ```CBONE_DISABLE_BACKUP_FILE```: don't generate the .old file

**function macros**


- ```cbone_da_free```: free a dynamic array.

- ```cbone_da_push```: push an element to the front of an array.

- ```cbone_da_pop```: remove an element on the front of the array.

- ```cbone_da_push_at```: push an element at position (adjust others to fit).

- ```cbone_da_pop_at```: remove an element at position (adjust others to fill).

- ```cbone_da_get```: gets an element at given position, if the position is greater
than the size, it will give the last element. Otherwise if it underflows the size, the first.

> [!NOTE]
> function macros that has the prefix `cbone_util_` will have their stripped version
> as an all uppercase word, for example, `cbone_util_cmd` will be only `CMD` 

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