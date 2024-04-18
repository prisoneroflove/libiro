#include "util.h"
// IDK HOW TO USE THIS
typedef struct Book {
  u32 id;
  char name[200];
  char author[20];
} Book;

/*TODO*/

void add_books(FILE *lib_appender, FILE *lib_reader, char *book_name,
               char *author_name);

u32 get_book_ID(FILE *lib_appender, FILE *lib_reader, char *book_name);
