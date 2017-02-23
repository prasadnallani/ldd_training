
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>

{
	
	
	
	
	
	    /* fill my buffer with *'s */ 
	    for (i = 0; i < 4000; i++)
		my_buf[i] = '*';
	
	    /* open the device for read/write/lseek */ 
	    printf("[%d] - Opening device veda_cdrv\n", getpid());
	
	
		
		
	
	
	
	    /* write the contents of my buffer into the device */ 
	    write(fd, my_buf, 4000);
	
	    /* empty my buffer now */ 
	    bzero(my_buf, 4000);
	
	    /* read 70 characters */ 
	    lseek(fd, 20, SEEK_SET);
	
	
	
	    /* empty by buffer again */ 
	    bzero(my_buf, 4000);
	
	    /* Write something into the buffer */ 
	    write(fd, "Veda Solutions", 14);
	
	    /* Set ppos to position 60 */ 
	    lseek(fd, 60, SEEK_SET);
	
	    /* read 70 characters and print */ 
	    read(fd, my_buf, 70);
	
	
	    /* Close the device */ 
	    close(fd);
	


