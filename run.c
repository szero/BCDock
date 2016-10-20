#include "utility.h"
#include "handle_scr.h"

#include <unistd.h>
#include <string.h>
#define CMD_IS(X) strcmp(argv[1], X) == 0

char dooloop = 1;
unsigned char posX,posY;
char color,time_pcs[2];
int cur_col,cur_ln,pos[2];

int main(int argc, char *argv[])
{
    init_screen();
    colors();
    if (argc < 2) {
        color=1;
        } else if (CMD_IS("-bk")) {
            color=2;
        } else if (CMD_IS("-rd")) {
            color=3;
        } else if (CMD_IS("-gr")) {
            color=4;
        } else if (CMD_IS("-yl")) {
            color=5;
        } else if (CMD_IS("-bl")) {
            color=6;
        } else if (CMD_IS("-mg")) {
            color=7;
        } else if (CMD_IS("-cy")) {
            color=8;
        } else if (CMD_IS("-wh")) {
            color=9;
    }
    while (dooloop) {
        if (return_key() == 113) dooloop =0;
        posX=cur_col/2-11;
        posY=cur_ln/2-4;
        win_size(pos);
        if (cur_ln != pos[0] || cur_col != pos[1]) {
            clr_scr();
            redraw();
            cur_ln = pos[0];
            cur_col = pos[1];
        }
        clr_scr();
        draw_bar(posX+0,posY+4,2,color);
        draw_bar(posX+3,posY+0,4,color);
        draw_bar(posX+8,posY+2,3,color);
        draw_bar(posX+11,posY+0,4,color);
        draw_bar(posX+16,posY+2,3,color);
        draw_bar(posX+19,posY+0,4,color);
        maketime();
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
        sleep(1);
    }
    end_window();
    return 0;
}
