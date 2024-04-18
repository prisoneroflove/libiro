#include "book.c"
#include "user.c"
#include "util.h"
#include <stdio.h>

#define LIB_FILE_NAME "library"
#define LOG_FILE_NAME "log"
#define USERS_FILE_NAME "users"

// May need to move to util
void file_validator(char *name) {
  FILE *temp_reader = fopen(name, "r");
  if (temp_reader == NULL) {
    FILE *temp_make = fopen(name, "w");
    if (temp_make == NULL) {
      char *format_str = (char *)malloc(sizeof(char) * 20);

      snprintf(format_str, 20, "Validator Failed : %s", name);
      debug_tool(format_str, Error);
      free(format_str);
    }
    fclose(temp_make);
  }
  fclose(temp_reader);
}

int main() {
  FILE *lib_read_write, *fp_appender;
  file_validator(LIB_FILE_NAME);
  lib_read_write = fopen(LIB_FILE_NAME, "r+");
  fp_appender = fopen(LIB_FILE_NAME, "a");

  file_validator(LOG_FILE_NAME);
  FILE *log_read_write = fopen(LOG_FILE_NAME, "r+");

  add_books(fp_appender, lib_read_write, "NIBBO", "KING");
  make_user("MM", "asdasds");
  get_num_instance(lib_read_write, "NIBBO");

  fclose(lib_read_write);
  fclose(log_read_write);
  fclose(fp_appender);
  return 0;
}
