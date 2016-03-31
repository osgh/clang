#include <stdio.h>

int main()
{

	char a = 'a';
	char b[] = {'b'};
	char c = '\0';
	char d = 'd';

	printf("%s\n", b);//b

	printf("%p\n",&a);
	printf("%p\n",b);
	printf("%p\n",&c);

	return 0;
}
