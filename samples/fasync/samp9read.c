/***********************************************************************
*                                                                      *
* SourceName         : samp9read.c                                     *
*                                                                      *
* Description        : This is an application program  to test the     *
*                      the driver (read method) sample8.               *
*                                                                      *
* Programmer         : ----------                                      *
* Date               : 15/07/2002                                      *
*                                                                      *
*----------------------------------------------------------------------*
* Notes                                                                *
* How To Build : On the command prompt give                            *
*                "gcc -o samp8read samp8read.c" this will give the     *
*                output file 'samp8read' which you can run.            *
*                                                                      *
* How To Load  : To run samp8read file give "./samp8read"              *
*                                                                      *
***********************************************************************/

/*----------------------------------------------------------------------
 ************************** Include File *******************************
 *--------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <fcntl.h>

/*--------------------------------------------------------------------*/

char device[]  = {"/dev/mydevice"};
char wbuff[32] = {"ABCDEFGHIJKLMNOP"};
char rbuff[32];

int gotdata=0;
void sighandler(int signo)
{
    if (signo==SIGIO)
    {
        gotdata++;
	printf("SIGIO received\n");
    };
    return;
}

char buffer[4096];

int main(int argc, char **argv)
{
    int count;
    struct sigaction action;
    int fd;

    fd = open(device, 0666);
    if (fd <= 0)
    {
      err_sys("Can not open the device\n");
    }

    memset(&action, 0, sizeof(action));
    action.sa_handler = sighandler;
    action.sa_flags = 0;

    sigaction(SIGIO, &action, NULL);

    fcntl(fd, F_SETOWN, getpid());
    fcntl(fd, F_SETFL, fcntl(fd, F_GETFL) | FASYNC);

    while(1) {
        /* this only returns if a signal arrives */
        sleep(86400); /* one day */
        if (!gotdata)
            continue;
        count=read(fd, buffer, 16);
        write(1,buffer,count);
        gotdata=0;
    }
    close(fd);
    exit(0);
}

/* display err message and exit */

err_sys(char *s)
{
  printf("%s\n", s);
  exit(1);
}

