#include <linux/module.h>
#include <linux/fs.h>
#include <asm/uaccess.h>
#include <linux/init.h>
#include <linux/cdev.h>
#include <linux/slab.h>

#define MAJORNO 300
#define MINORNO  0
#define CHAR_DEV_NAME "veda_cdrv"
#define MAX_LENGTH 4000
#define SUCCESS 0





{
	
		
		
		
		
	
	
	



{
	
	



				 size_t lbuf, loff_t * ppos) 
{
	
	
	
		char_device_buf, nbytes);
	



	    THIS_MODULE, 
	    char_dev_open, 
};


{
	
	
	
	
	
	
	
		
		
	
	
	
	



{
	
	
	







/* End of code */ 