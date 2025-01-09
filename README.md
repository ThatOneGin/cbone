# Cbone

Cbone is a one-header ibrary to make c build files

**Note: this is experimental and anything can change at any moment.**

The main idea of this is that you only need a C compiler to build a project.

Take a look into [test.c](./test.c) for a more detailed overview.

One feature it has is self rebuilding, if the macro ```REBUILD_SELF``` encounters any difference between the executable build file and the source code, it tries to recompile itself.

Here's how to use:

```c
#define CBONE_IMPL
#include "cbone.h"

int main(int argc, char **argv) {
  REBUILD_SELF(argc, argv);

  // build code goes here.

  return 0;
}
```

You need to define ```CBONE_IMPL``` because it is a one header library so if this macro is defined, the preprocessor will also include the implementation section.