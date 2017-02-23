
#include<linux/module.h>
#include<linux/version.h>
#include<linux/kernel.h>

static int counter;

void func ()
{
	printk ("Counter val %d\n ", counter);
}

int myinit (void)
{
	printk ("intialising counter\n ");
	counter = 100;
	return 0;
}

void myexit (void)
{
	printk ("module removed\n ");
}

//EXPORT_SYMBOL (func);

EXPORT_SYMBOL_GPL (func);

/*Kernel module Comments*/
MODULE_AUTHOR ("TEAM VEDA");
MODULE_DESCRIPTION ("Test module: exporting symbols");
MODULE_LICENSE ("GPL");
