#pragma once
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define u32 uint32_t

typedef enum DebugType {
  Error,
  Warn,
  Done,
  Log,
} DebugType;

void debug_tool(char *s, DebugType status);
u32 generate_ID(FILE *lib_reader);
u32 get_id_search(FILE *lib_reader, char *search_name);
int get_num_instance(FILE *reader, char *search_name);
char *get_taken_time();
