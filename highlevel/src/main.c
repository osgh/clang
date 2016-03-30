#include <stdio.h>

#include "count_highlevel.h"

int main()
{

	int space = 0xffff00f0;
	unsigned char *addr = (unsigned char *)&space;

	printf("the space (value:0x%x) has %ld highlevel(s).\n", space, count_highlevel(addr, sizeof(int)));

	printf("the space that any space in memory has %ld highlevel(s).\n",count_highlevel((unsigned char *)main, 1000));

	printf("%d\n",10000);

	return 0;
}
