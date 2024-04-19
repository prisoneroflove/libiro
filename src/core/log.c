#include "log.h"
#include "util.c"
#include "util.h"
#include <stdio.h>

int is_book_taken(FILE *log_reader, FILE *lib_reader, char *book_name) {
  int log_num = get_num_instance(log_reader, book_name);
  int lib_num = get_num_instance(lib_reader, book_name);
  return (lib_num - log_num > 0);
}

void take_book(FILE *log_appender, u32 user_id, u32 book_id) {
  fprintf(log_appender, "%dU %dB %s", user_id, book_id, get_taken_time());
}

FILE *add_to_old_log(FILE *log_read_write, FILE *old_log_append, char *username,
                     char *log_file_name) {
  int current_line = 0, flag = 0;
  char line[100];

  int num_instances = get_num_instance(log_read_write, username);

  int *positions = malloc(num_instances * sizeof(int));

  get_id_search_with_skip(log_read_write, username, positions);

  FILE *temp = fopen("temp", "w");

  while (fgets(line, sizeof(line), log_read_write)) {
    current_line += 1;
    flag = 0;
    for (int i = 0; i < num_instances; i++) {
      if (current_line == positions[i]) {
        flag = 1;
      }
    }
    if (flag) {
      fputs(line, old_log_append);
    } else {
      fputs(line, temp);
    }
  }
  if (remove(log_file_name) != 0) {
    debug_tool("Couldn't remove Log file for adding to log", Error);
  }
  if (rename("temp", log_file_name) != 0) {
    debug_tool("Couldn't rename file for adding to old log", Error);
  }
  free(positions);
  return temp;
}
