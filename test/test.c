#define CBONE_IMPL
#include "cbone.h"

void build_tool(char *tool) {
  Str_Array buildsep = make_str_array("build", "bin", tool, NULL);
  Str_Array target = make_str_array(tool, ".cpp", NULL);
  char *aspath = concat_str_array(path_sep, buildsep);
  char *targetdotc = concat_str_array("", target);
  
  CMD(cc, "-o", aspath, targetdotc);

  free(aspath);
  free(targetdotc);
  free(target.elm);
  free(buildsep.elm);

  /* using macros:
    CMD(cc, "-o", PATH("build", "bin", tool), CONCAT(tool, ".c"));
  */
}

int main(int argc, char **argv) {
  // if this macro encounters any difference between the last write time
  // of the original source code and the binary, it will recompile itself
  // automatically.
  REBUILD_SELF(argc, argv);
  
  build_tool("mybillionaireapp");
	// actually prediction
  build_tool("minecraft2");
  return 0;
}
