#include "book.h"

void add_books(FILE *lib_appender, FILE *lib_reader, char *book_name,
               char *author_name) {
  u32 id = generate_ID(lib_reader);
  fprintf(lib_appender, "B%d %s %s\n", id, book_name, author_name);
}

// Returns 0 if made
u32 get_book_ID(FILE *lib_appender, FILE *lib_reader, char *book_name) {
  u32 id = get_id_search(lib_reader, book_name);
  if (id != 0) {
    return id;
  }
  debug_tool("Couldn't find the Book", Error);
  debug_tool("Adding the book in to the registry", Warn);
  // Add book author_name
  // or just a warn, then adding should be manual
  add_books(lib_appender, lib_reader, book_name, NULL);
  return 0;
}
