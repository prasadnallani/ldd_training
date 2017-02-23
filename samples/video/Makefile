#Makefile for a multi-filed module

obj-m += video-buf.o
obj-m += v4l2-common.o
obj-m += v4l1-compat.o
obj-m += videodev.o
obj-m += vivi.o

all:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules

clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean

