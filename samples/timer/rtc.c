/*
 * rtc.c: real time clock 146818, reading time of day
 *
 * Compile with `gcc -O2 -o rtc rtc.c',
 * and run as root with `./rtc'.
 */

#include <stdio.h>
#include <unistd.h>
#include <asm/io.h>

#define AddrReg 0x70
#define DataReg 0x71

int main()
{
  unsigned char second, minute, hour;
  unsigned char day, month, year;

  /* Get access to the ports */
  if (ioperm(AddrReg, 2, 1))
  {
     perror("ioperm");
     exit(1);
  }
  
  /* select the addr register by outputting reg number
     and read the value */
  outb(0x00, AddrReg);
  second = inb(DataReg);

  outb(0x02, AddrReg);
  minute = inb(DataReg);

  outb(0x04, AddrReg);
  hour = inb(DataReg);

  outb(0x07, AddrReg);
  day = inb(DataReg);

  outb(0x08, AddrReg);
  month = inb(DataReg);

  outb(0x09, AddrReg);
  year = inb(DataReg);

  /* display the time of day */
  printf("%c%c/%c%c/%c%c - %c%c:%c%c:%c%c\n",
			((day & 0xf0) >> 4) + 0x30,
			(day & 0x0f) + 0x30,
			((month & 0xf0) >> 4) + 0x30,
			(month & 0x0f) + 0x30,
			((year & 0xf0) >> 4) + 0x30,
			(year & 0x0f) + 0x30,
			((hour & 0xf0) >> 4) + 0x30,
			(hour & 0x0f) + 0x30,
			((minute & 0xf0) >> 4) + 0x30,
			(minute & 0x0f) + 0x30,
			((second & 0xf0) >> 4) + 0x30,
			(second & 0x0f) + 0x30
	);

  /* We don't need the ports anymore */
  if (ioperm(AddrReg, 2, 0))
  {
    perror("ioperm");
    exit(1);
  }

  exit(0);
}
