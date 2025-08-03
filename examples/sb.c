#define CBONE_IMPL
#include "cbone.h"

/*
** Simple function to concatenate an array of strings
** sep being 0 means no separator needed
*/
cbone_string_builder concat_table(char **table, char sep) {
  cbone_string_builder sb = cbone_sb_new();
  char **old = table;
  char *elm = table[0];
  while (elm != NULL) {
    cbone_sb_sprintf(&sb, "%s", elm); /* put the content */
    if (sep != 0) cbone_sb_char(&sb, sep); /* put the separator */
    elm = *(++table); /* advance element */
  }
  table = old; /* restore table */
  return sb;
}

int main() {
  char *table[] = {
    "Hello,",
    "World!",
    NULL
  };
  cbone_string_builder sb = concat_table(table, ' ');
  printf("%s\n", cbone_sb_cstr(&sb));
  cbone_sb_free(&sb);
  return 0;
}
