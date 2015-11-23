#include "utility.h"
#include "handle_scr.h"

#include <unistd.h>
char dooloop = 1;
int key_press;
unsigned char posX,posY;
char time_pcs[2];
int cur_col,cur_ln,pos[2];

int main(void)
{
    init_screen();
    colors();
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
    draw_bar(posX+0,posY+4,2);
    draw_bar(posX+3,posY+0,4);
    draw_bar(posX+8,posY+2,3);
    draw_bar(posX+11,posY+0,4);
    draw_bar(posX+16,posY+2,3);
    draw_bar(posX+19,posY+0,4);
    split_nr(time_pcs,cur_hr());
    draw_time(posX+0,posY+0,time_pcs[0],2);
    draw_time(posX+3,posY+0,time_pcs[1],4);
    split_nr(time_pcs,cur_min());
    draw_time(posX+8,posY+0,time_pcs[0],3);
    draw_time(posX+11,posY+0,time_pcs[1],4);
    split_nr(time_pcs,cur_sec());
    draw_time(posX+16,posY+0,time_pcs[0],3);
    draw_time(posX+19,posY+0,time_pcs[1],4);
    redraw();
    usleep(1000);
    }
end_window();
return 0;
}        
