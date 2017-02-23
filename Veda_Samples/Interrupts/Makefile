obj-m := inttest.o
obj-m += timer.o
obj-m += hrexamp.o
obj-m += wrkqueue.o
obj-m += mytasklet.o
obj-m += taskletcount.o
obj-m += taskletdynamic.o
obj-m += taskletqueue.o
obj-m += interrupt.o
obj-m += intthread.o
obj-m += intthread1.o
obj-m += uiostub.o


KDIR= /lib/modules/$(shell uname -r)/build

all:
	$(MAKE) -C $(KDIR) SUBDIRS=$(PWD) modules

clean:
	rm -rf $(wildcard *.o *.ko mo* Mo* *.mod.c )
