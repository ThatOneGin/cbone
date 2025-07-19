#define CBONE_IMPL
#include "cbone.h"

int main() {
  cbone_string_builder sb = cbone_sb_new();
  cbone_sb_sprintf(&sb, "Hello, %s!%c", "world", 10);
  printf("%s", cbone_sb_cstr(&sb));
  cbone_sb_free(&sb);
  return 0;
}
