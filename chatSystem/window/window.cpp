#include "window.h"

WINDOW* window::get_header()
{
  return header;
}

WINDOW* window::get_flist()
{
  return flist;
}

WINDOW* window::get_output()
{
  return output;
}

WINDOW* window::get_input()
{
  return input;
}

window::window()
{
  initscr();//COLS:列（宽度） LINES:行（高度）
}

void window::put_string_to_window(WINDOW *w, int y, int x, std::string &message)
{
  mvwaddstr(w, y, x, message.c_str()); 
  wrefresh(w);
}

void window::get_string_from_window(WINDOW *w, std::string &out_string)
{
  char buf[SIZE];
  wgetnstr(w, buf, SIZE);
  out_string = buf;
}

void window::draw_header()
{
  int y = 0;
  int x = 0;
  int h = LINES / 5;
  int w = COLS;

  header = newwin(h, w, y, x);
  box(header, '+', '=');
  wrefresh(header);
}

void window::draw_ouput()
{

  int y = LINES / 5;
  int x = 0;
  int h = LINES * 3 / 5;
  int w = COLS * 3 / 4;

  output = newwin(h, w, y, x);
  box(output, 0, 0);
  wrefresh(output);
}

void window::draw_flist()
{
  int y = LINES / 5;
  int x = COLS * 3 / 4;
  int h = LINES * 3 / 5;
  int w = COLS / 4;

  flist = newwin(h, w, y, x);
  box(flist, 0, 0);
  wrefresh(flist);
}

void window::draw_input()
{
  int y = LINES * 4 / 5;
  int x = 0;
  int h = LINES / 5;
  int w = COLS;

  input = newwin(h, w, y, x);
  box(input, 0, 0);
  wrefresh(input);
}

window::~window()
{
  endwin();
}

//int main()
//{
//  window w;
//  w.draw_header();
//  w.draw_ouput();
//  w.draw_flist();
//  w.draw_input();
//  
//  std::string message = "Please Enter# ";
//  
//  std::string str;
//  while (1)
//  {
//    w.put_string_to_window(w.get_input(), 1, 2, message);
//    w.get_string_from_window(w.get_input(), str);
//    w.draw_input();
//  }
//
//  //std::string message = "for test....!";
//  //int y, x;
//  //int i = 1;
//  //while (1)
//  //{
//  //  getmaxyx(w.get_output(), y, x);
//  //  w.put_string_to_window(w.get_output(), i++, 2, message);
//  //  if (i > y - 1)
//  //  {
//  //    i = 1;
//  //    w.draw_ouput();
//  //  }
//  //  usleep(300000);
//  //}
//  //
//  //
//  //
//  //std::string title = "Please Enter Chat System!";
//  //int i = 1;
//  //int y, x;
//  //int dir = 0;
//  //while (1)
//  //{
//  //  //解决重影
//  //  w.draw_header();
//  //  getmaxyx(w.get_header(), y, x);
//  //  w.put_string_to_window(w.get_header(), y / 2, i, title);
//  //  if (i >= x - title.size() - 3)
//  //  {
//  //    //左 <- 右
//  //    dir = 1;
//  //  }
//  //  if (i <= 4)
//  //  {
//  //    dir = 0;
//  //  }
//  //  if (dir == 0)
//  //  {
//  //    i++;
//  //  }
//  //  else 
//  //  {
//  //    i--;
//  //  }
//  //  i %= (x - title.size());
//  //  usleep(10000);
//  //}
//  return 0;
//}
//
//
