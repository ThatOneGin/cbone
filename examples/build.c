/*
** Example of how to use basic functions of the library.
*/
#define CBONE_IMPL
#include "cbone.h"

// the non-leaking way to use.
void raw_build_tool(char *tool) {
  Str_Array buildsep = cbone_make_str_array("build", "bin", tool, NULL);
  Str_Array target = cbone_make_str_array(tool, ".cpp", NULL);
  char *aspath = cbone_concat_str_array(path_sep, buildsep);
  char *targetdotc = cbone_concat_str_array("", target);
  
  CMD(cc, "-o", aspath, targetdotc);

  free(aspath);
  free(targetdotc);
  free(target.items);
  free(buildsep.items);
}

// the easiest and non-verbose way to use.
void build_tool(char *tool) {
  CMD(cc, "-o", PATH("build", "bin", tool), CONCAT(tool, ".c"));
}

int main(int argc, char **argv) {
  // if this macro encounters any difference between the last write time
  // of the original source code and the binary, it will recompile itself
  // automatically.
  REBUILD_SELF(argc, argv);

  raw_build_tool("mybillionaireapp");

  // jokes aside, actually a prediction.
  build_tool("minecraft2");
  return 0;
}
