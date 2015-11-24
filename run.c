#include "utility.h"
#include "handle_scr.h"

#include <unistd.h>
#include <string.h>

//#define CMD_IS(X) strcmp(cmd, X) == 0
char dooloop = 1;
int key_press;
unsigned char posX,posY;
char color,time_pcs[2];
int cur_col,cur_ln,pos[2];

int main(int argc, char *argv[])
{
    init_screen();
    colors();
    if (argc < 2) {
        color=1;
        } else if (strcmp(argv[1],"-bk") == 0) {
            color=2;    
        } else if (strcmp(argv[1],"-rd") == 0) {
            color=3;
        } else if (strcmp(argv[1],"-gr") == 0) {
            color=4;
        } else if (strcmp(argv[1],"-yl") == 0) {
            color=5;
        } else if (strcmp(argv[1],"-bl") == 0) {
            color=6;    
        } else if (strcmp(argv[1],"-mg") == 0) {
            color=7;
        } else if (strcmp(argv[1],"-cy") == 0) {
            color=8;
        } else if (strcmp(argv[1],"-wh") == 0) {
            color=9;
    }
    
    while (dooloop) {
    key_press = return_key();
    if (key_press == 113) dooloop =0;
    posX=cur_col/2-11;
    posY=cur_ln/2-3;
    win_size(pos);
    if (cur_ln != pos[0] || cur_col != pos[1]) {
        clr_scr();
        cur_ln = pos[0];
        cur_col = pos[1];
    }
    maketime();
    draw_bar(posX+0,posY+4,2,color);
    draw_bar(posX+3,posY+0,4,color);
    draw_bar(posX+8,posY+2,3,color);
    draw_bar(posX+11,posY+0,4,color);
    draw_bar(posX+16,posY+2,3,color);
    draw_bar(posX+19,posY+0,4,color);
    split_nr(time_pcs,cur_hr());
    draw_time(posX+0,posY+0,time_pcs[0],2,color);
    draw_time(posX+3,posY+0,time_pcs[1],4,color);
    split_nr(time_pcs,cur_min());
    draw_time(posX+8,posY+0,time_pcs[0],3,color);
    draw_time(posX+11,posY+0,time_pcs[1],4,color);
    split_nr(time_pcs,cur_sec());
    draw_time(posX+16,posY+0,time_pcs[0],3,color);
    draw_time(posX+19,posY+0,time_pcs[1],4,color);
    redraw();
    usleep(1000);
    }
end_window();
return 0;
}        
