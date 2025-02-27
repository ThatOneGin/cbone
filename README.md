# Cbone

Cbone is a one-header library to make build files

**Note: this is experimental and anything can change at any moment.**

The main idea of this is that you only need a C compiler to build a project.

Take a look into [test.c](./test/test.c) for a more detailed overview.

One feature it has is self rebuilding, if the macro ```REBUILD_SELF``` encounters any difference between the executable build file and the source code, it tries to recompile itself.

Here's how to use:

```c
#define CBONE_IMPL
#include "cbone.h"

int main(int argc, char **argv) {
  REBUILD_SELF(argc, argv);

  CMD(cc, "-o", "main", "main.c", "-Wall", "-Wextra", "-pedantic");
  
  // rest of the build code

  return 0;
}
```

# Cbone's utilities

## Macros for dynamic arrays (utilities)

**customizable macros**:
  
```DA_DEFAULT_CAP```: minimum capacity for arrays (customizable)

```DA_ASSERT```: assertion method used in errors (customizable)

**function macros**:

```DA_FREE```: free a dynamic array.

```DA_PUSH```: push an element to the front of an array

```DA_POP```: remove an element on the front of the array.

```DA_PUSH_AT```: push an element at position (adjust others to fit)

```DA_POP_AT```: remove an element at position (adjust others to fill)

```DA_GET```: gets an element at given position, if the position is greater
than the size, it will give the last element. Otherwise if it underflows the size, the first.

## Declare dynamic arrays

```c
typedef struct {
  void *items; // can be a pointer of any type
  size_t size; // any integer type, but its better to be a size_t
  size_t capacity; // also any integer type
} DynArr;
```

Any struct with these 3 fields (items, size and capacity) can be used with these macros and also
can have more fields.