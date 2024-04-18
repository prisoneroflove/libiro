#include "util.h"
#include <string.h>
#define MAX_USERNAME_SIZE 40
#define MAX_PASSWORD_SIZE 16
typedef struct User {
  char name[MAX_USERNAME_SIZE];
  char password[MAX_PASSWORD_SIZE];
} User;
void add_user(FILE *usr_rgstr, User user);

int check_dupli_users(FILE *lib_reader, char *name);

User make_user(char *username, char *pass);
