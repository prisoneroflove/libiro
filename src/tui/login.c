#include "include/login.h"
#include <stdio.h>

int validate() {
  char username[100], password[100];
  int hasAccess = 0;
  printf("Welcome\n");
  printf("Enter your username: ");
  fgets(username, 100, stdin);
  printf("Enter your password: ");
  fgets(password, 100, stdin);

  if (strstr(username, "ashwin")) {
    if (strstr(password, "admin@123")) {
      hasAccess = 1;
    }
  }
  return hasAccess;
}

FILE *change_username(FILE *writer, char *username) {
  char line[100];
  FILE *temp = fopen("temp", "w");
  int indx = 0;
  while (fgets(line, sizeof(line), writer)) {
    if (indx == 0) {
      fputs(username, temp);
    } else {
      fputs(line, temp);
    }
    indx++;
  }
  // ADD ERROR HADNLING
  remove("mob");
  rename("temp", "mob");
  return temp;
}

FILE *change_password(FILE *writer, char *password) {
  char line[100];
  FILE *temp = fopen("temp", "w");
  int indx = 0;
  while (fgets(line, sizeof(line), writer)) {
    if (indx == 0) {
      fputs(line, temp);
    } else {
      fputs(password, temp);
    }
    indx++;
  }
  // ADD ERROR HADNLING
  remove("mob");
  rename("temp", "mob");
  return temp;
}
