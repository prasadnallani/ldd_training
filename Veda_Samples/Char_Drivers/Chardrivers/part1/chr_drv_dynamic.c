#include <linux/module.h>
#include <linux/fs.h>
#include <asm/uaccess.h>
#include <linux/init.h>
#include <linux/cdev.h>
#include <linux/sched.h>
#include <linux/errno.h>
#include <asm/current.h>
#include <linux/slab.h>

#define CHAR_DEV_NAME "veda_cdrv"
#define MAX_LENGTH 4000
#define SUCCESS 0




{
	
	



{
	



				 
{
	
	
					  buf, /* from */ 
					  lbuf);	/* how many bytes */
	
	
		char_device_buf, nbytes);
	



	    THIS_MODULE, 
	    char_dev_open, 
};


{
	
	
		
		
	
	
		
		
		
	
	
	
	
		
		
		
		
	
	
	
		MAJOR(mydev), MINOR(mydev));
	
	



{
	
	
	
	






