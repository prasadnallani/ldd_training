#include<linux/kernel.h>
#include<linux/version.h>
#include<linux/module.h>
#include<linux/moduleparam.h>

static int base_port[5];
static int irq;
static char *name=0;

module_param_array(base_port,int,NULL,0);
MODULE_PARM_DESC(base_port,"base_port=v1,v2,v3...\n");

module_param(irq,int,0644);
MODULE_PARM_DESC(irq,"irq=v1\n");

module_param(name,charp,0644);
MODULE_PARM_DESC(name,"name=\n");

void myinit(void)
{
	 printk(KERN_INFO"MODULE INSERTED");
	int i;
	pr_info("irq=%d\t,name=%s\n",irq,name);
	for(i=0;i<5;i++)
	pr_info("%d\n",base_port[i]);
        return 0;

}
void myexit(void)
{
        printk("MODULE REMOVED");
	 int i;
        pr_info("irq=%d\t,name=%s\n",irq,name);
        for(i=0;i<5;i++)
        pr_info("%d\n",base_port[i]);


}

module_init(myinit);
module_exit(myexit);

MODULE_AUTHOR("suport@rohit.org");
MODULE_DESCRIPTION("LKD_CW:first kernel");
MODULE_LICENSE("GPL");
                                                                                                                                              
                                                                                                                                              
                             
