video driver example
  vivi.c
    Virtual Video driver - This code emulates a real video device with v4l2
    api

  insmod v4l2-common.ko
  insmod video-buf.ko
  insmod v4l1-compat.ko
  insmod videodev.ko
  insmod vivi.ko
  v4lgrab
