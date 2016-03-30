#include "count_highlevel.h"
#include "ones_counter.h"

long count_highlevel(const unsigned char *addr, int len)
{
	long counter = 0;
	int i = 0;

	for(i = 0; i <len; i++){
		counter += uchar_ones_count(addr[i]);
	}

	return counter;
}
