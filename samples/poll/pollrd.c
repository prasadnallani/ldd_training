/***********************************************************************
*                                                                      *
* SourceName         : pollrd.c                                        *
*                                                                      *
* Description        : This is an application program to test the      *
*                      the driver (read method) poll.                  *
*                                                                      *
* Programmer         : ----------                                      *
* Date               : 4/10/2009                                       *
*                                                                      *
*----------------------------------------------------------------------*
* Notes                                                                *
* How To Build : On the command prompt give                            *
*                "gcc -o pollrd pollrd.c" this will give the           *
*                output file 'pollrd' which you can run.               *
*                                                                      *
* How To Load  : To run pollrd file give "./pollrd"                    *
*                                                                      *
***********************************************************************/

/*----------------------------------------------------------------------
 ************************** Include File *******************************
 *--------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <poll.h>
/*--------------------------------------------------------------------*/

char device[]  = {"/dev/mydevice"};
char rbuff[32];
struct pollfd fds;
int nfds=1;

/* start of main program */

main()
{
   int fd, nb;
   int nr;

   fd = open(device, 0666);
   if (fd <= 0)
   {
     err_sys("Can not open the device\n");
   }

   nr = 0;
   while (!nr)
   {
     fds.fd = fd;
     fds.events = POLLIN;
     nr = poll(&fds, nfds, 10000);
     printf("Events %d %04x\n", nr, fds.revents);
     if (nr > 0)
     {
       nb = read(fd, rbuff, 16);
       printf("No. of Bytes Read = %d\n", nb);
       write(1, rbuff, nb);
       printf("\n");
     }
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

