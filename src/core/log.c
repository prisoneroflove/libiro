#include "log.h"
#include "util.c"
#include <stdio.h>

int is_book_taken(FILE *log_reader, char *book_name) {
  char c;
  // checking array
  char arr[5] = {0};
  // id making array
  char char_array[4] = {0};
  int indx = 0;
  while (1) {
    c = fgetc(log_reader);
    // Exit if end of file
    if (feof(log_reader)) {
      return 0;
      break;
      // add an error?
    }
    // clear the list if whitespace or newline
    arr[indx] = c;
    if (c == '\n' || c == ' ') {
      if (arr[0] == 'B') {
        for (int i = 1; i < indx; i++) {
          char_array[i] = arr[i];
        }
        return atoi(char_array); // Got ID
      }
      // If no B, clear everything
      for (int i = 0; i < 5; i++) {
        arr[i] = 0;
      }
      indx = 0;
    }
    indx += 1;
  }
}

void take_book(FILE *log_appender, u32 user_id, u32 book_id) {
  fprintf(log_appender, "%dU %dB %s", user_id, book_id, get_taken_time());
}
