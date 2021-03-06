/*
 * I/O Port
*/


#include <linux/module.h>
#include <linux/init.h>
#include <linux/fs.h>
#include <linux/ioport.h>

#define MY_MAJOR	250

int major;

struct file_operations my_fops;
unsigned long start, len;

int my_init(void)
{
        int sts;
	start = 0x378;
	len = 0x4;
        printk("<1>Hello World\n");
        major = register_chrdev(MY_MAJOR,"mydevice",&my_fops);
	request_region(start,len,"mydevice");

	return 0;
}

void my_cleanup(void)
{
        printk("<1> Goodbye\n");
	release_region(start, len);
        unregister_chrdev(MY_MAJOR,"mydevice");
}

module_init(my_init);
module_exit(my_cleanup);

MODULE_LICENSE("GPL");

