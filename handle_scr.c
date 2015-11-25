#include "handle_scr.h"

#include <ncurses.h>
#include <stdlib.h>

static WINDOW *okno;
static WINDOW* mainwin;


void init_screen(void)
{
    mainwin = initscr();
    cbreak();
    noecho();
    nodelay(mainwin, TRUE);
    curs_set(0);
    refresh();
    wrefresh(mainwin);
    okno = newwin(0,0,0,0);
    
}

void colors(void)
{

        if(has_colors() == FALSE) {
        endwin();
        printf("Your terminal doesn\'t even have 50 shades od gray ...\n");
        exit(1);
        }
        use_default_colors();
        start_color();
        init_pair(1, -1, -1);
        init_pair(2, COLOR_BLACK, -1);
        init_pair(3, COLOR_RED, -1);
        init_pair(4, COLOR_GREEN, -1);
        init_pair(5, COLOR_YELLOW, -1);
        init_pair(6, COLOR_BLUE, -1);
        init_pair(7, COLOR_MAGENTA, -1);
        init_pair(8, COLOR_CYAN, -1);
        init_pair(9, COLOR_WHITE, -1);

}

void draw_bar(unsigned char posX,unsigned char posY, int box_nr, char pair)
{
    unsigned int y1,y2,x1,x2;
    y1 = posY;
    x1 = posX;
    y2 = posY+1;
    x2 = posX+2;
    unsigned char i;
    for (i = 0; i < box_nr*2; i=i+2) {
        if (i == 0) {
            y1=y1+i;
            y2=y2+i;
        } else {
            y1 = y1+2;
            y2 = y2+2;
        }
        wattron(okno, COLOR_PAIR(pair));
        mvwhline(okno, y1, x1, 0, x2-x1);
        mvwhline(okno, y2, x1, 0, x2-x1);
        mvwvline(okno, y1, x1, 0, y2-y1);
        mvwvline(okno, y1, x2, 0, y2-y1);
        mvwaddch(okno, y1, x1, ACS_ULCORNER);
        mvwaddch(okno, y2, x1, ACS_LLCORNER);
        mvwaddch(okno, y1, x2, ACS_URCORNER);
        mvwaddch(okno, y2, x2, ACS_LRCORNER);
        wattroff(okno, COLOR_PAIR(pair));
    }
  
}

void draw_time(unsigned char posX, unsigned char posY, char bar, char bar_size, char pair)
{  
    char i,pos;
    pos =0;

    for(i=bar_size-1; i>=0; i--) {
        if (bar&(1<<(bar_size-1-i))){
            wattron(okno,A_REVERSE | COLOR_PAIR(pair));
            mvwaddch(okno,posY+6-pos,posX+1,ACS_HLINE);
            wattroff(okno,A_REVERSE | COLOR_PAIR(pair));
    
        } else {
            wattron(okno,COLOR_PAIR(pair));
            mvwaddch(okno,posY+6-pos,posX+1,ACS_HLINE);
            wattroff(okno,COLOR_PAIR(pair));
        } 
            pos = pos + 2;
    }
}

void win_size(int pos[])
{   
    getmaxyx(okno, pos[0], pos[1]);
}

void redraw(void)
{
    wrefresh(okno);
    refresh(); 
}

void clr_scr(void)
{
    int ln,col,i,j;
    getmaxyx(okno,ln,col);
    for (i = 0; i < ln; ++i) {
        for (j = 0; j < col; ++j) {
            wattron(okno,COLOR_PAIR(2));
            mvwaddch(okno,i,j,32);
            wattroff(okno,COLOR_PAIR(2));
        }
    }    
}

int return_key(void)
{
    return getch();
}


void end_window(void)
{
    endwin();
}
