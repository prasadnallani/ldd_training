#include  <stdlib.h>
#include  <stdio.h>
#include  <unistd.h>
#include  <fcntl.h>

int main()
{
	int fd;
	unsigned long nint;
	if ((fd = open("/dev/uio0", O_RDONLY)) < 0) {
		perror("Failed to open /dev/uio0\n");
		exit(EXIT_FAILURE);
	}
	while (read(fd, &nint, sizeof(nint)) >= 0)
		printf("Interrupts: %ld\n", nint);
	return 0;
}
