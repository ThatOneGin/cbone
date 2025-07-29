# Cbone

Cbone is a one-header library to make build files.

**Note: this is experimental and anything can change at any moment.**
**Cbone is also very unstable and should not be used for large builds.**

The main idea of this is that you only need a C compiler to build a project and doesn't need to get
track of the build system's version.

Take a look into [this](examples/README.md) for a more detailed overview.

# Installation

You can just copy-and-paste `cbone.h` into your project.

# Usage

Here is a minimal build file which compiles `main.c`.

```c
#define CBONE_IMPL
#include "cbone.h"

int main(int argc, char **argv) {
  /*
  ** this macro checks for any difference in the last
  ** time the source file was saved, and if there's a difference,
  ** it tries to recompile itself.
  */
  REBUILD_SELF(argc, argv);

  /*
  ** CMD is like writting in a shell, it creates the process with given arguments.
  ** cc is a macro used to identify which C compiler was used to compile the source file.
  */
  CMD(cc, "-o", "main", "main.c", "-Wall", "-Wextra", "-pedantic");

  return cbone_errcode;
}
```

# When to not use Cbone

- When you already use a build system like [Cmake][https://cmake.org/] or [GNU Make](https://www.gnu.org/software/make/), it doesn't make any sense to use Cbone.
- When your project is too big, Cbone is meant to be used in tiny projects.

# Pros and cons

## Pros

- You write more C
- Code reuse (you use the same language for building and developing your project)
- Portability (works on Windows and most Linux systems)

## Cons

- You need to be comfortable with implementing things by yourself
- Useless in projects that don't use C or C++
- Verbosity, as already mentioned, you write more C

# Acknowledgements

This library is heavily inspired by [nob.h](https://github.com/tsoding/nob.h) and mostly on its predecessor [nobuild](https://github.com/tsoding/nobuild).