#include "utility.h"

#include <time.h>

char now_sec, now_min, now_hour, now_day, now_wday,now_month,now_year;

time_t now;
struct tm *now_tm;
/*
static char count(unsigned char i)
{
    char ret=1;
    while (i/=10) ret++;
    return ret;
}
*/
void split_nr(char parts[],char nr_to_split)
{
    int dig=2;
    while (dig--)
    {
    parts[dig]=nr_to_split%10;
    nr_to_split/=10;
    }
}

void maketime(void)
{
    now = time (NULL);
    now_tm = localtime(&now);
    now_sec = now_tm->tm_sec;
    now_min = now_tm->tm_min;
    now_hour = now_tm->tm_hour;
    now_day = now_tm->tm_mday;
    now_wday = now_tm->tm_wday;
    now_month = now_tm->tm_mon + 1;
    now_year = now_tm->tm_year + 1900;
}

char cur_hr(void)
{
    return now_hour;
}

char cur_min(void)
{
    return now_min;
}

char cur_sec(void)
{
    return now_sec;
}
