#include "tui/login.c"
#include "tui/util.c"
#include <string.h>

int main() {
  if (!validate()) {
    printf("Wrong Username or Password\n");
    return 0;
  }
  display_commands();
  char string_buffer[MAX_STRING_BUFFER_SIZE];

  while (!strstr(string_buffer, "quit")) {
    get_input(string_buffer);
    if (strstr(string_buffer, "help")) {
      display_commands();
    } else if (strstr(string_buffer, "clear")) {
      clear_screen();
    }
  }
}
