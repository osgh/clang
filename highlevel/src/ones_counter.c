#include "ones_counter.h"

int uint_ones_count(unsigned int ui)
{
	int counter = 0;

	while(ui){
		if(ui&1){
			counter++;
		}
		ui = ui>>1;
	}

	return counter;
}

int int_ones_count(int i)
{
	int counter = 0;
	int flag = 1<<(sizeof(int)*8-1);
		
	while(i){
		if(i&flag){
			counter++;
		}
		i = i<<1;
	}

	return counter;
}


int uchar_ones_count(unsigned char uc)
{
	int counter = 0;

	while(uc){
		if(uc&1){
			counter++;
		}
		uc = uc>>1;
	}

	return counter;
}
