#include <stdio.h> 

#define NAME_LEN 63

typedef struct person {
	int id;
	char name[NAME_LEN+1];
	void (*fun)(char *);
} person, *ptr_person;

void say(char *);

int main()
{
	person zhangsan = {1, "zhangsan", say};

	zhangsan.fun(zhangsan.name);

	return 0;
}

void say(char *str)
{
	printf("%s\n", str);
}
