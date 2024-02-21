#pragma once
#include "util.h"

void debug_tool(char *s, DebugType status) {
  switch (status) {
  case Error:
    printf("Error: %s\n", s);
    break;
  case Warn:
    printf("Warn : %s\n", s);
    break;
  case Done:
    printf("Done: %s\n", s);
    break;
  case Log:
    printf("Log: %s\n", s);
  }
}

u32 generate_ID(FILE *lib_reader) {
  if (lib_reader == NULL) {
    debug_tool("Couldn't generate id. Invalid filename/file missing", Error);
    exit(-1);
  }
  // fputs("HELLO", libFile);
  u32 count = 0;
  char c;
  // while(true)
  while (1) {
    c = fgetc(lib_reader);
    if (feof(lib_reader)) {
      break;
    }
    if (c == '\n') {
      count++;
    }
  }
  return count + 1;
}
char *get_taken_time() {
  time_t tm;
  time(&tm);
  return ctime(&tm);
}

// TODO CAN BUG PROBABLABY

// 0 if not found
u32 get_id_search(FILE *lib_reader, char *search_name) {
  u32 id;
  char line[100];
  // search each line till you find the word
  while (fgets(line, sizeof(line), lib_reader) != NULL) {
    if (strstr(line, search_name) != NULL) {
      return id;
    }
    id += 1;
  }
  return 0;
}
