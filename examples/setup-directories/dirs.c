#define CBONE_IMPL
#define CBONE_STRIP_PREFIX
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
  CBONE_DA_FREE(path);
  CBONE_DA_FREE(bin_dir);
  CBONE_DA_FREE(src_dir);
}

int main(int argc, char **argv) {
  REBUILD_SELF(argc, argv);
  setup_dirs();
  return cbone_errcode;
}
