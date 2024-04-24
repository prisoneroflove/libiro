#include "include/util.h"
#include <stdio.h>

void clear_screen() {
#if defined(__unix__)
  system("clear");

#else
  system("cls")

#endif
}
void display_commands() {
  printf("\nThese are the basic commands:\nhelp - To print this message\tadd - "
         "To add books to library\nclear - To clear the screen\tquit - TO quit "
         "the application\n");
}

void get_input(char *string_buffer) {
  printf(">>");
  fgets(string_buffer, MAX_STRING_BUFFER_SIZE, stdin);
}
