/**
 * @name ci-main.cpp
 * @subject For CI Testing
 * @author SCaffrey(sirius.caffrey@gmail.com)
 * @Copyright DWTFABG
 * @comment This is a file for CI testing.
 */
#include <cstdio>
#include <cstdlib>
#include <cstring>


char buf[100033], tee[1033];
int id = 0;
int main() {
  system("bash generate_cpp_list.sh > file.list");
  freopen("file.list", "r", stdin);
  gets(buf);
  system(buf);
  freopen("files.log", "r", stdin);
  while (gets(tee)) {
    if (strstr(tee, "Total")) {
      if (strcmp(tee, "Total errors found: 0")) {
        fprintf(stderr, "%s\n", tee);
        return 1;
      } else {
        fprintf(stderr, "Passed CppLint Tests!\n");
        return 0;
      }
    }
  }
  return 0;
}
