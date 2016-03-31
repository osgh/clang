#include <stdio.h>

int main()
{

	int arr[5] = {1, 2, 3, 4, 5};
	int (*ptr)[5] = &arr+1;

	printf("%p\n",arr);
	printf("%p\n",arr+1);

	printf("%p\n",&arr);
	printf("%p\n",&arr+1);

	printf("%p\n",ptr);
	printf("%p\n",ptr+1);

	printf("%lu\n",sizeof(arr));
	printf("%lu\n",sizeof(&arr));
	printf("%lu\n",sizeof(ptr));
	printf("%lu\n",sizeof(*ptr));

	*arr = 6;
	printf("%d\n",arr[0]);
	return 0;
}
