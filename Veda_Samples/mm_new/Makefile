obj-m :=alloc_page.o
obj-m +=structpage.o
obj-m +=ptdump.o
obj-m +=mycache.o
#obj-m +=dma_test.o
obj-m +=dma_test11.o
obj-m +=dma_test11111.o
obj-m +=dma_test2.o
obj-m +=dma_test3.o



KDIR= /lib/modules/$(shell uname -r)/build

all:
	$(MAKE) -C $(KDIR) SUBDIRS=$(PWD) modules
clean: 
	 rm -rf $(wildcard *.o *.ko *.mod.* .c* .t* test Module.symvers *.order *.markers)
