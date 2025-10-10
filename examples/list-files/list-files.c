#define CBONE_IMPL
#include "cbone.h"

int main() {
  const char *path = ".";
  printf("listing files on '%s':\n", path);
  cbone_foreach_file_in(path, {
    printf("\t%s\n", filename);
  });
  return 0;
}
