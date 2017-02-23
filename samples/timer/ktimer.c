/***********************************************************************
*                                                                      *
* SourceName         : ktimer.c                                        *
* ModuleName         : ktimer.o                                        *
*                                                                      *
* Description        : This sample program shows how to implement      *
*                      a simple kernel timer.                          *
*                                                                      *
* Programmer         : ----------                                      *
* Date               : 15/07/2002                                      *
*                                                                      *
*----------------------------------------------------------------------*
* Notes                                                                *
* How To Build : On the command prompt type make 		       *
*                						       *
* How To Load  : To load the ktimer.o file give "insmod ktimer.o",    *
*                this will load the module to the kernel.              *
*                                                                      *
***********************************************************************/

/*----------------------------------------------------------------------
 ************************** Include File *******************************
 *--------------------------------------------------------------------*/

#include <linux/module.h>
#include <linux/timer.h>
#include <linux/sched.h>

/*--------------------------------------------------------------------*/

struct timer_list mytimer;

void timeout_function(unsigned long something) 
{
  printk("<1>\n\n\n***** Kernel Timer Expired Arg is %d *****\n\n", something);
  /* reinitialize the timer, for periodic */

  mytimer.function = timeout_function;
  mytimer.data	 = 777;
  mytimer.expires  = jiffies + 10*HZ;
  add_timer(&mytimer);

  /* OR modify and reactivate, for periodic timer */
//  mod_timer(&mytimer, (long)(jiffies+20*HZ));
}

int ktimer_init(void)
{
	init_timer(&mytimer);

	mytimer.function = timeout_function;
	mytimer.data	 = 777;
	mytimer.expires  = jiffies + 5*HZ;

	add_timer(&mytimer);

        printk("<1>\n\n\n***** Kernel Timer Demo Module Initialized ****\n\n");
	return 0;
}

void ktimer_exit(void)
{
	del_timer(&mytimer);
        printk("<1>\n\n\n***** Kernel Timer Demo Module Cleanup *****\n\n");
}

module_init(ktimer_init);
module_exit(ktimer_exit);

MODULE_LICENSE("GPL");

