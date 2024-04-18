
#include <ncurses.h>
#include <stdarg.h>
#include <stdlib.h>
void quit(int num, ...) {
  va_list va;

  va_start(va, num);

  for (int i = 0; i < num; i++) {
    free(va_arg(va, char *));
  }
  endwin();
}
int main() {
  int MAX_X = 0, MX_Y = 0;
  char *str = malloc(100 * sizeof(char));
  initscr();
  getmaxyx(stdscr, MAX_X, MX_Y);
  WINDOW *win = newwin(15, 17, 1, MX_Y - (MX_Y / 3));
  clear();
  printw(">>");
  getstr(str);

  box(win, 0, 0);
  mvwprintw(win, 0, 1, str);
  wrefresh(win);
  refresh();
  if (getch() == 'q') {
    quit(1, str);
  }
}
