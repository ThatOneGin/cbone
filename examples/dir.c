/*
** Example use of the functions that manipulate directories.
*/

#define CBONE_IMPL
#include "cbone.h"

void setup_dirs(void) {
  cbone_str_array path = cbone_make_str_array(".", "build", NULL);
  cbone_str_array bin_dir = cbone_make_str_array(".", "build", "bin", NULL);
  cbone_str_array src_dir = cbone_make_str_array(".", "src", NULL);
  if (cbone_dir_exists(path) == 0) {
    char *bin = cbone_concat_str_array(path_sep, bin_dir);
    cbone_dir_mkdir("build");
    cbone_dir_mkdir(bin);
    free(bin);
  }
  if (cbone_dir_exists(src_dir) == 0) {
    char *src = cbone_concat_str_array(path_sep, src_dir);
    cbone_dir_mkdir(src);
    free(src);
  }
  DA_FREE(path);
  DA_FREE(bin_dir);
  DA_FREE(src_dir);
}

int main(int argc, char **argv) {
  REBUILD_SELF(argc, argv);
  setup_dirs();
  /* this variable is automatically set to 1 if any error occur. */
  return cbone_errcode;
}
