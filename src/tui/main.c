#include <ncurses.h>

int main() {
  initscr();
  clear();
  move(10, 20);
  printw(">>");

  mvprintw(21, 10, "YO");

  refresh();
  getch();

  endwin();
}
