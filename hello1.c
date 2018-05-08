#include<linux/kernel.h>
#include<linux/version.h>
#include<linux/module.h>

void func(void)
{
	printk(KERN_INFO"hello");

}
int myinit(void)
{
	printk(KERN_INFO"MODULE INSERTED");
	return 0;

}
void myexit(void)
{
	printk("MODULE REMOVED");

}

module_init(myinit);
module_exit(myexit);
EXPORT_SYMBOL_GPL(func);
MODULE_AUTHOR("suport@rohit.org");
MODULE_DESCRIPTION("LKD_CW:first kernel");
MODULE_LICENSE("GPL");
