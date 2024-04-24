#pragma once

#include <stdio.h>
#include <string.h>

int validate();

FILE *change_username(FILE *writer, char *username);
FILE *change_password(FILE *writer, char *password);
