#include <stdio.h>	/* printf */
#include <stdlib.h>	/* malloc, atoi, rand... */
#include <string.h>	/* memcpy, strlen... */
#include <stdint.h>	/* uints types */
#include <sys/types.h>	/* size_t ,ssize_t, off_t... */
#include <unistd.h>	/* close() read() write() */
#include <fcntl.h>	/* open() */
#include <sys/ioctl.h>	/* ioctl() */
#include <errno.h>	/* error codes */

// ioctl commands defined for the pci driver header
#include "../../include/ioctl_cmds.h"

int main(int argc, char** argv)
{
	int fd, retval;

	if (argc < 2) {
		printf("Syntax: %s <device file path>\n", argv[0]);
		return -EINVAL;
	}

	if ((fd = open(argv[1], O_RDWR)) < 0) {
		fprintf(stderr, "Error opening file %s\n", argv[1]);
		return -EBUSY;
	}

	unsigned int data2 = 0xFFFFFFFF;
	 unsigned int data = 0xFFFFFFFF;
	ioctl(fd, WR_L_DISPLAY);
	retval = write(fd, &data, sizeof(data));
	printf("WR_L_DISPLAY %d bytes\n", retval);

	ioctl(fd, WR_R_DISPLAY);
	retval = write(fd, &data2, sizeof(data2));
	printf("WR_R_DISPLAY %d bytes\n", retval);

	unsigned int data3 = 0x00000000;
	ioctl(fd, WR_RED_LEDS);
	retval = write(fd, &data3, sizeof(data3));
	printf("WR_RED_LEDS %d bytes\n", retval); 	


	unsigned int data6 = 0x00;
	ioctl(fd, WR_GREEN_LEDS);
	retval = write(fd, &data6, sizeof(data6));
	printf("WR_GREEN_LEDS %d bytes\n", retval); 	


	unsigned int data4 = 0x0;
	ioctl(fd, RD_PBUTTONS);
	retval = read(fd, &data4, 1);
	printf("RD_PBUTTONS  %d bytes\n", data4); 	
	

	unsigned int data5;
	ioctl(fd, RD_SWITCHES);
	retval = read(fd, &data5, 4);
	printf("RD_SWITCHES  %d bytes\n", data5); 	

	close(fd);
	return 0;
}
