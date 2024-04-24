// File name LOG
#include "../util.c"

int is_book_taken(FILE *log_reader, FILE *lib_reader, char *book_name);
void take_book(FILE *log_appender, u32 user_id, u32 book_id);

// for old_log
// FILE* to return the new log file
FILE *add_to_old_log(FILE *log_read_write, FILE *old_log_append, char *username,
                     char *log_file_name);
