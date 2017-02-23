/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*                                                                      *
* ModuleName         :  isamem.o                                       *
* SourceName         :  isamem.c                                       *
*                                                                      *
* Description        : Accessing Physical Memory (A0000-FFFFF)         *
*                                                                      *
* Programmer         :---------                                        *
* Date               : 27/4/2006                                       *
*                                                                      *
*----------------------------------------------------------------------*
* Notes:                                                               *
*                                                                      *
*                                                                      *
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
 
/*----------------------------------------------------------------------
 ************************** Include File *******************************
 *----------------------------------------------------------------------*/
#include <linux/module.h>
#include <asm/io.h>

char *ptr;		/* virtual address for video buffer */

/*---------------------------------------------------------------------
 ************************** INIT MODULE *******************************
 *--------------------------------------------------------------------*/

int isamem_init (void)
{
    int i;
    
    printk ("---------Hello----------\n");
   
    isa_writeb('A', 0xB8000);
  
    return 0;
}

/*---------------------------------------------------------------------
 ************************** CLEANUP MODULE ****************************
 *--------------------------------------------------------------------*/

void isamem_exit (void)
{
    printk ("---------BYE----------\n");
}

module_init(isamem_init);
module_exit(isamem_exit);

MODULE_LICENSE("GPL");

