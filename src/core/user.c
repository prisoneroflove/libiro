#include "include/user.h"
// For generating id
User make_user(char *username, char *pass) {
  User user;
  for (int i = 0; i < 40; i++) { // 40 is max size of username
    strncpy(user.name, username, MAX_USERNAME_SIZE);
  }
  for (int i = 0; i < 16; i++) { // 16 is max size of password
    strncpy(user.password, pass, MAX_PASSWORD_SIZE);
  }
  debug_tool(user.name, 4);
  return user;
}

int check_dupli_users(FILE *lib_reader, char *name) {
  u32 is_dup = get_id_search(lib_reader, name);
  if (is_dup != 0) {
    return 1;
  }
  return is_dup;
}

void add_user(FILE *usr_rgstr, User user) {
  u32 id = generate_ID(usr_rgstr);
  fprintf(usr_rgstr, "U%d %s %s\n", id, user.name, user.password);
}
