#include "log.h"
#include "util.c"
#include <stdio.h>

int is_book_taken(FILE *log_reader, char *book_name) {
  char c;
  char arr[5] = {0};
  while (1) {
    c = fgetc(log_reader);
    if (feof(log_reader)) {
      break;
    }
    if (c == '\n') {
      for (int i = 0; i < 5; i++) {
        arr[i] = 0;
      }
    }
    char line[100];
    // search each line till you find the word
    while (fgets(line, sizeof(line), log_reader) != NULL) {
      if (strstr(line, book_name) != NULL) {
      }
    }
  }
}

void take_book(FILE *log_appender, u32 user_id, u32 book_id) {
  fprintf(log_appender, "%dU %dB %s", user_id, book_id, get_taken_time());
}
