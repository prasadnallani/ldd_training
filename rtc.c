#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/delay.h>
#include <asm/io.h>

#define  SECOND         0x00  //Second       (00..59) 
#define  MINUTE         0x02  //Minute       (00..59)
#define  HOUR           0x04  //Hour         (00..23) 
#define  DAY_IN_WEEK    0x06  //Day of week  (01..07)
#define  DAY            0x07  //Day          (01..31) 
#define  MONTH          0x08  //Month        (01..12) 
#define  YEAR           0x09 // Year         (00..99) 

#define  ADDRESS_REG       0x70
#define  DATA_REG          0x71
#define  ADDRESS_REG_MASK  0xe0

static unsigned char rtc_inb(unsigned char addr)
{
	outb(addr, ADDRESS_REG);
	return inb(DATA_REG);
}

static void rtc_outb(unsigned char data, unsigned char addr)
{
	
	outb(addr, ADDRESS_REG);
	outb(data, DATA_REG);
}

static int __init rtc_init(void)
{

	printk("rtc module loaded\n");	

	printk("second %x\n", rtc_inb(SECOND));
	printk("minute %x\n", rtc_inb(MINUTE));
	printk("hour %x\n", rtc_inb(HOUR));
	printk("day %x\n", rtc_inb(DAY));
	printk("month %x\n", rtc_inb(MONTH));
	printk("year %x\n", rtc_inb(YEAR));

	return 0;
		
}

static void __exit rtc_exit(void)
{
	printk("rtc module unloaded\n");
}

module_init(rtc_init);
module_exit(rtc_exit);

MODULE_LICENSE("GPL");

