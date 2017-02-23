/***********************************************************************
*                                                                      *
* SourceName         : sample9.c                                       *
* ModuleName         : sample9.o                                       *
*                                                                      *
* Description        : This sample program shows an implementation of  *
*                      character device driver with blocking i/o       *
*                      (Wait Queue)                                    *
*                                                                      *
*                                                                      *
* Programmer         : ----------                                      *
* Date               : 18/09/2003                                      *
*                                                                      *
*----------------------------------------------------------------------*
* Notes                                                                *
* How To Build : On the command prompt give "gcc -c sample9.c",this    *
*                will compile and give 'sample9.o' file which you can  *
*                load.                                                 *
* How To Load  : To load the sample9.o file give "insmod sample9.o",   *
*                this will load the module to the kernel.              *
*                                                                      *
***********************************************************************/
/*----------------------------------------------------------------------
 ************************** Define File ********************************
 *--------------------------------------------------------------------*/

#define  MY_MAJOR        250

/*----------------------------------------------------------------------
 ************************** Include File *******************************
 *--------------------------------------------------------------------*/

#include <linux/module.h>
#include <linux/init.h>
#include <linux/fs.h>
#include <linux/fs.h>
#include <linux/fcntl.h>
#include <asm/uaccess.h>

/*--------------------------------------------------------------------*/

int major;
char kbuf[64];

struct fasync_struct *async_queue;	/* asynchronous readers */

/* fasync method, to handle asynchronous notification */
int my_fasync(int fd, struct file *filp, int mode)
{
	printk("Owner %d\n", filp->f_owner);
	return(fasync_helper(fd, filp, mode, &async_queue));
}
/*****************************************************************************
****	When application calls int open(const char *pathname, int flags), ****
****	my_open() method will be invoked by the Kernel, which returns	  ****
****	the file descriptor for the device or -1 if any error occurs	  ****
*****************************************************************************/

static int my_open(struct inode *inode, struct file *filp){
	int minor;

        minor = MINOR(filp->f_dentry->d_inode->i_rdev);
        printk("\n****Some body is opening me at minor %d****\n",minor);
        return 0;
}

/****************************************************************************
****	When application calls int close(int fd), where fd is the file	 ****
****	descriptor returned by corresponding open(),			 ****
****	my_open() method will be invoked by the Kernel, which returns	 ****
****	0 on success and -1 on error					 ****
****************************************************************************/

static int my_close(struct inode *inode, struct file *filp){
        int minor;

        minor = MINOR(filp->f_dentry->d_inode->i_rdev);
        printk("*****Some body is closing me at minor %d*****\n",minor);
	my_fasync(-1, filp, 0);
        return 0;
}

/****************************************************************************
** When application calls ssize_t read(int fd, void *buf, size_t count), ****
** where fd is the file descriptor returned by corresponding open(),	 ****
** buf is user buffer, and count is the number of bytes requested,	 ****
** my_read() method will be invoked by the Kernel, which returns	 ****
** number of bytes actually transferred or -1 on error	  	         ****
****************************************************************************/


ssize_t my_read(struct file *filp, char *buf, size_t count, loff_t *offset){
        int minor;
        minor = MINOR(filp->f_dentry->d_inode->i_rdev);
        printk("*****Some body is reading me at minor %d*****\n",minor);
	copy_to_user(buf, kbuf, count);
        return count;
}

/*******************************************************************************
** When application calls ssize_t write(int fd, const void *buf, size_t count),*
** where fd is the file descriptor returned by corresponding open(),	      **** buf is user buffer with data, and count is the number of bytes to be       **
** written,my_write() method will be invoked by the Kernel, which returns     **
** number of bytes actually transferred or -1 on error			      **
*******************************************************************************/

ssize_t my_write(struct file *filp, const char *buf, size_t count, loff_t *offset){
        int minor;

        minor = MINOR(filp->f_dentry->d_inode->i_rdev);
        printk("*****Some body is writing me at minor*****\n",minor);
	copy_from_user(kbuf, buf, count);
        kbuf[count] = 0;
        printk("User Data: %s\n", kbuf); 
	kill_fasync(&async_queue, SIGIO, POLL_IN);
        return count;
}

/******************************************************************************
****	When application calls int ioctl(int fd, int request char *argp),  ****
****	where fd is the file descriptor returned by corresponding open(),  ****
****	request is command, and argp is a pointer to argument list,        ****
****	my_ioctl() method will be invoked by the Kernel, which returns	   ****
****	0 or a positive integer on success or -1 on error		   ****
******************************************************************************/

int my_control(struct inode *inode, struct file *filp, unsigned int command, unsigned long argument){
	int minor;

        minor = MINOR(filp->f_dentry->d_inode->i_rdev);
        printk("*****Some body is controlling me at minor %d*****\n",minor);
        return 0;
}

struct file_operations my_fops = {
        read    :       my_read,
        write   :       my_write,
        open    :       my_open,
        release :       my_close,
        ioctl   :       my_control,
	fasync  :	my_fasync,
        owner   :       THIS_MODULE,
        };

int my_init(void) {
        printk("<1>Hello World\n");
        major = register_chrdev(MY_MAJOR,"mydevice",&my_fops);
        return 0;}

void my_cleanup(void) {
        printk("<1> Goodbye\n");
        unregister_chrdev(MY_MAJOR,"mydevice");}


module_init(my_init);
module_exit(my_cleanup);

