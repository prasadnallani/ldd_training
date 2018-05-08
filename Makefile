obj-m :=hello1.o
obj-m +=hello2.o
obj-m +=import.o
obj-m +=export.o
obj-m +=rtc.o
obj-m +=modparam.o
obj-m +=page.o
obj-m +=chardrv1.o
obj-m +=chardrv2.o
obj-m +=chardrv3.o

KDIR= /lib/modules/$(shell uname -r)/build

all:
	$(MAKE) -C $(KDIR) M=$(PWD) modules
clean: 
	 @rm -rf $(wildcard *.o *.ko *.mod.* .c*  .*.cmd .t* test Module.symvers *.order *.markers a.out)
