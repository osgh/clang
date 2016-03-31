#include <stdio.h>

int main()
{

	enum WEEK{
		WEEK_MON,
		WEEK_SUN,
	};

	printf("%lu\n", sizeof(enum WEEK));

	return 0;
}
