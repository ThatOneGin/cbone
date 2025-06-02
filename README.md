# Cbone

Cbone is a one-header library to make build files.

**Note: this is experimental and anything can change at any moment.**
**Cbone is also very unstable and should not be used for large builds.**

The main idea of this is that you only need a C compiler to build a project and doesn't need to get
track of the build system's version.

Take a look into [this](examples/README.md) for a more detailed overview.

Here's a simple way to use it:

```c
#define CBONE_IMPL
#include "cbone.h"

int main(int argc, char **argv) {
  // this macro checks for any difference in the last
  // time the source file was saved, and if there's a difference,
  // it tries to recompile itself.
  REBUILD_SELF(argc, argv);

  // CMD creates a process (first parameter) and use the rest as arguments
  // for the proccess.
  // for example:
  CMD(cc, "-o", "main", "main.c", "-Wall", "-Wextra", "-pedantic");

  return cbone_errcode;
}
```

# Acknowledgements

This library is heavily inspired by [nob.h](https://github.com/tsoding/nob.h) and mostly on its predecessor [nobuild](https://github.com/tsoding/nobuild).