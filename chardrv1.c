#include<linux/kernel.h>
#include<linux/fs.h>
#include<linux/cdev.h>
#include<linux/version.h>
#include<linux/module.h>

 static dev_t dev;/*creating instance of dev_t to hold major no. and minor no.*/

static struct cdev *cdev;/*creating struct instance will hold file_operation pointer*/

static int drv_open (struct inode *inode, struct file *file)
{
	pr_info("open invoked\n");
	return 0;

}
static  ssize_t drv_read (struct file *file, char __user *buf, size_t size, loff_t *len)
{
	pr_info("read invoked\n");
	return 0;
}

static  ssize_t drv_write (struct file *file, const char __user *buf, size_t size, loff_t *len)
{
	pr_info("write invoked\n");
	return 0;
}

static int drv_release (struct inode *inode, struct file *file)
{
	pr_info("release invoked\n");
	return 0;

}

struct file_operations drv_operations ={
	.read=drv_read,
	.write=drv_write,
	.open=drv_open,
	.release=drv_release

};




static __init int mydrv_init(void)
{
	/*regestering device*/
	dev=MKDEV(300,0);

	/*regestering memory region for char device*/
	register_chrdev_region(dev,1,"rohit_drv");

	/*calling this fn to allocate a cdev object in data segment not in stack*/
	cdev=cdev_alloc();

	if(cdev==NULL)
	{
		pr_err("no memory\n");
		return -1;
	}
	/*initializing cdev object with our implemented operations*/
	cdev_init(cdev,&drv_operations);
	/*adding the cdev object to vfs */
	cdev_add(cdev,dev,1);

	pr_info("driver included\n");
	
}

static __exit void mydrv_exit(void)
{
	/*deleting cdev object*/
	cdev_del(cdev);
	/*releasing memory region for device*/
	unregister_chrdev_region(dev,1);

	pr_info("module removed\n");

}

module_init(mydrv_init);
module_exit(mydrv_exit);

MODULE_LICENSE("GPL");
