#include "util.h"

typedef struct User {
  char name[40];
  char password[16];
} User;
void add_user(FILE *usr_rgstr, User user);

int check_dupli_users(FILE *lib_reader, char *name);

User make_user(char *username, char *pass);
