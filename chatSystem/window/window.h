#pragma once 

#include <iostream>
#include <ncurses.h>
#include <unistd.h>

#define SIZE 1024
class window 
{
  public:
    window();
    void put_string_to_window(WINDOW *w, int y, int x, std::string &message);
    
    void get_string_from_window(WINDOW *w, std::string &out_string);
    void draw_header();
    void draw_ouput();
    void draw_flist();
    void draw_input();
    WINDOW* get_header();
    WINDOW* get_flist();
    WINDOW* get_output();
    WINDOW* get_input();
    ~window();
  private:
    WINDOW* header;
    WINDOW* output;
    WINDOW* flist;
    WINDOW* input;
};
