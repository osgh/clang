#include "swap.h"

void char_swap(char *p, char *q)
{
	char tmp;

	tmp = *p;
	*p = *q;
	*q = tmp;
}

void int_swap(int *p, int *q)
{
	int tmp;

	tmp = *p;
	*p = *q;
	*q = tmp;
}
