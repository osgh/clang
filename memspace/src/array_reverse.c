#include "array_reverse.h"
#include "swap.h"
void array_reverse(int *arr, int len)
{
	int index = len/2;
	int i = 0;
	int *p = arr;
	int *q = arr + len - 1;

	while(i<index){
		int_swap(p++, q--);
		i++;
	}
}
