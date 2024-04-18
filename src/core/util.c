#pragma once
#include "util.h"

void debug_tool(char *err, DebugType status) {
  switch (status) {
  case Error:
    printf("Error: %s\n", err);
    break;
  case Warn:
    printf("Warn : %s\n", err);
    break;
  case Done:
    printf("Done: %s\n", err);
    break;
  case Log:
    printf("Log: %s\n", err);
  }
}

u32 generate_ID(FILE *lib_reader) {
  // remove validator and make it when the program starts in the main file
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

// 0 if not found
int get_num_instance(FILE *reader, char *search_name) {
  char line[100];
  int num = 0;

  while (fgets(line, sizeof(line), reader) != NULL) {
    if (strstr(line, search_name) != NULL) {
      num += 1;
    }
  }
  return num;
}
u32 get_id_search(FILE *lib_reader, char *search_name) {
  u32 id = 0;
  char line[100];
  // search each line till you find the word
  while (fgets(line, sizeof(line), lib_reader) != NULL) {
    if (strstr(line, search_name) != NULL) {
      return id + 1;
    }
    id += 1;
  }
  return 0;
}
