// File name LOG
#include "util.c"

int is_book_taken(FILE *log_reader, FILE *lib_reader, char *book_name);
void take_book(FILE *log_appender, u32 user_id, u32 book_id);
int is_book_taken(FILE *log_reader, char *name);
