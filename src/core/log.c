#include "log.h"
#include "util.c"
#include <stdio.h>

int is_book_taken(FILE *log_reader, FILE *lib_reader, char *book_name) {
  int log_num = get_num_instance(log_reader, book_name);
  int lib_num = get_num_instance(lib_reader, book_name);
  return (lib_num - log_num > 0);
}

void take_book(FILE *log_appender, u32 user_id, u32 book_id) {
  fprintf(log_appender, "%dU %dB %s", user_id, book_id, get_taken_time());
}
