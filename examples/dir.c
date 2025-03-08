/*
** Example use of the functions that manipulate directories.
*/

#define CBONE_IMPL
#include "cbone.h"

void setup_dirs(void) {
  Str_Array path = cbone_make_str_array(".", "build", NULL);
  Str_Array bin_dir = cbone_make_str_array(".", "build", "bin", NULL);
  Str_Array src_dir = cbone_make_str_array(".", "src", NULL);
  if (cbone_dir_exists(path) == 0) {
    char *bin = cbone_concat_str_array(path_sep, bin_dir);
    cbone_mkdir("build");
    cbone_mkdir(bin);
    free(bin);
  }
  if (cbone_dir_exists(src_dir) == 0) {
    char *src = cbone_concat_str_array(path_sep, src_dir);
    cbone_mkdir(src);
    free(src);
  }
  DA_FREE(path);
  DA_FREE(bin_dir);
  DA_FREE(src_dir);
}

int main(int argc, char **argv) {
  REBUILD_SELF(argc, argv);
  setup_dirs();
  return 0;
}
