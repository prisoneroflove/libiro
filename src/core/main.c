#include "book.c"
#include "user.c"
#include <stdio.h>

int main() {
  FILE *fp_writer, *fp_reader, *fp_appender;
  fp_writer = fopen("library", "w");
  fp_reader = fopen("library", "r");
  fp_appender = fopen("library", "a");

  FILE *log_reader = fopen("log", "r");
  if (fp_writer == NULL || fp_reader == NULL || fp_appender == NULL) {
    debug_tool("file open error fp", Error);
    return -1;
  }

  add_books(fp_appender, fp_reader, "NIBBO", "KING");
  make_user("MM", "asdasds");
  get_num_instance(fp_reader, "NIBBO");

  fclose(fp_writer);
  fclose(log_reader);
  fclose(fp_appender);
  fclose(fp_reader);
  return 0;
}
