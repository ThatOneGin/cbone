#define CBONE_STRIP_PREFIX
#define CBONE_IMPL
#include "cbone.h"

#define NFILES 3 /* Extend if needed */
#define CFLAGS "-Wall", "-Wextra"
#define SRC(f) "src" path_sep f ".c"
#define OBJ(f) "bin" path_sep f ".o"

char *sources[NFILES] = {
  SRC("foo"),
  SRC("bar"),
  SRC("main")
};

char *objects[NFILES] = {
  OBJ("foo"),
  OBJ("bar"),
  OBJ("main")
};

void compile_src_to_obj(void) {
  /* cc -c [CFLAGS] -o [BUILD] */
  for (int i = 0; i < NFILES; i++) {
    CMD(cc, "-c", CFLAGS, sources[i], "-o", objects[i]);
  }
}

void compile_obj_to_exe(void) {
  /* cc -o cbone-test-build [FILES] */
  cbone_cmd cmd = {0};
  cmd_append(&cmd, cc);
  cmd_append(&cmd, "-o");
  cmd_append(&cmd, "cbone-test-build");
  for (int i = 0; i < NFILES; i++) {
    cmd_append(&cmd, objects[i]);
  }
  cmd_run_sync(&cmd);
  cmd_free(&cmd);
}

int main(int argc, char **argv) {
  REBUILD_SELF(argc, argv);
  compile_src_to_obj();
  compile_obj_to_exe();
  return 0;
}
