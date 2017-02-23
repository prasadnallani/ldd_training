/***********************************************************************
*                                                                      *
* SourceName         : pollwr.c                                        *
*                                                                      *
* Description        : This is an application program  to test the     *
*                      the driver (write method) poll.                 *
*                                                                      *
* Programmer         : ----------                                      *
* Date               : 4/10/2009                                       *
*                                                                      *
*----------------------------------------------------------------------*
* Notes                                                                *
* How To Build : On the command prompt give                            *
*                "gcc -o pollwr pollwr.c" this will give the           *
*                output file 'pollwr' which you can run.               *
*                                                                      *
* How To Load  : To run pollwr file give "./pollwr"                    *
*                                                                      *
***********************************************************************/

/*----------------------------------------------------------------------
 ************************** Include File *******************************
 *--------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>

/*--------------------------------------------------------------------*/

char device[]  = {"/dev/mydevice"};
char wbuff[32] = {"ABCDEFGHIJKLMNOP"};

main()
{
   int fd, nb;

   fd = open(device, 0666);
   if (fd <= 0)
   {
     err_sys("Can not open the device\n");
   }
   nb = write(fd, wbuff, 16);
   if (nb != 16)
     err_sys("Write Error\n");
   printf("No. of Bytes Written = %d\n", nb);
   close(fd);
   exit(0);
}

/* display err message and exit */

err_sys(char *s)
{
  printf("%s\n", s);
  exit(1);
}

