#pragma once
#include "util.h"
#include <stdio.h>

void debug_tool(char *err, DebugType status) {
  char str[100];
  switch (status) {
  case Error:
    snprintf(str, 100, "Error: %s", err);
    perror(str);
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
  rewind(lib_reader);
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
  rewind(reader);
  return num;
}

// id is just the nth line the word/book/unsername is
u32 get_id_search(FILE *lib_reader, char *search_name) {
  u32 id = 0;
  char line[100];
  // search each line till you find the word
  while (fgets(line, sizeof(line), lib_reader) != NULL) {
    if (strstr(line, search_name) != NULL) {
      rewind(lib_reader);
      return id + 1;
    }
    if (strchr(line, '\n')) {
      id += 1;
    }
  }
  rewind(lib_reader);
  return 0;
}
// position is malloced outside
void get_id_search_with_skip(FILE *lib_reader, char *search_name,
                             int *positions) {
  int line_num = 0;
  int found_count = 0;
  int num_of_occurance = get_num_instance(lib_reader, search_name);

  char line[100];
  while (fgets(line, sizeof(line), lib_reader)) {
    line_num++;
    char *found = strstr(line, search_name);
    while (found) {
      positions[found_count++] = line_num;
      found = strstr(found + 1, search_name);
    }
  }
  rewind(lib_reader);
}
