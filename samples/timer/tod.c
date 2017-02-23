/*
 * gettimeofday()
 */
#include <sys/time.h>
#include <time.h>
#include <stdio.h>
#include <unistd.h>

struct timeval gtime;
struct tm *cur_time;
struct tm rtime;

int main(int argc, char *argv[])
{
   gettimeofday(&gtime, NULL);
   cur_time = localtime(&gtime.tv_sec);
   printf("%02d-%02d-%04d %02d:%02d:%02d\n",
		  cur_time->tm_mday, cur_time->tm_mon+1, cur_time->tm_year+1900,
		  cur_time->tm_hour, cur_time->tm_min, cur_time->tm_sec);
   
   localtime_r(&gtime.tv_sec, &rtime);
   printf("%02d-%02d-%02d %02d:%02d:%02d\n",
		  rtime.tm_mday, rtime.tm_mon+1, rtime.tm_year+1900,
		  rtime.tm_hour, rtime.tm_min, rtime.tm_sec);
   printf("%s", asctime(&rtime));
}

