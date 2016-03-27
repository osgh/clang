#include <stdio.h>
#include "string_utils.h"
#include "ones_counter.h"
#include "array_reverse.h"

int main()
{

	printf("\n");

	/* count string blanks */
	printf("\"hello world\" has %d blank(s)\n",count_blanks("hello world"));

	
	printf("\n");
	

	/* remove blanks of string */
	char str[50] = "h ell o wo rl d!"; 
	remove_blanks(str,50);
	printf("\"h ell o wo rl d!\" remove blanks is \"%s\"\n",str);


	printf("\n");


	/* count ones of integer number */
	int ones = 0xfffffff0;
	printf("ones of %d total are %d\n", ones, int_ones_count(ones));


	printf("\n");


	/* reverse array of integer numbers */
	int arr[] = {1,2,3,4,5,6,7,8,9};
	int len = sizeof(arr)/sizeof(arr[0]);

	array_reverse(arr, len);
	
	printf("1 2 3 4 5 6 7 8 9 reversed to ");
	int i;
	for(i = 0; i < len; i++){
		printf("%d ",arr[i]);
	}

	printf("\n");

	return 0;
}
