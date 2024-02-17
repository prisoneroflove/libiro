#include "book.c"
#include "user.c"
#include <stdio.h>

int main() {
  FILE *fp_writer, *fp_reader, *fp_appender;
  fp_writer = fopen("library", "w");
  fp_reader = fopen("library", "r");
  fp_appender = fopen("library", "a");
  if (fp_writer == NULL || fp_reader == NULL || fp_appender == NULL) {
    debug_tool("file open error fp", Error);
    return -1;
  }

  add_books(fp_appender, fp_reader, "NIBBO", "KING");
  make_user("MM", "asdasds");

  fclose(fp_writer);
  fclose(fp_appender);
  fclose(fp_reader);
  return 0;
}
