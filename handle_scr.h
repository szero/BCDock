#ifndef __SCR_HANDLER__
#define __SCR_HANDLER__
void init_screen(void);
void colors(void);
void draw_bar(unsigned char posX,unsigned char posY, int box_nr, char pair);
void draw_time(unsigned char posX, unsigned char posY, char bar, char bar_size, char pair);
void win_size(int pos[]);
void redraw(void);
void clr_scr(void);
int return_key(void);
void end_window(void);
#endif /* ifndef __SCR_HANDLER__ */
