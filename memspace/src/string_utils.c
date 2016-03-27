#include "string_utils.h"
#include <stdio.h>
int count_blanks(char *const str)
{
	int i = 0;
	int counter = 0;

	while(str[i]){
		if(str[i] == ' '){
			counter++;
		}	
		i++;
	}

	return counter;
}

void remove_blanks(char *const arr, int len)
{
	char tmp[len];
	char *p = tmp;	
	int i = 0;

/*	while(arr[i] && i < len){

		if(arr[i] != ' '){
			*(p++) = arr[i];
			i++;
		}else{
			i++;
			continue;
		}
	}
*/	
	for(i = 0; i < len; i++){

		if(arr[i] != ' '){
			*(p++) = arr[i];
		}

		if(!arr[i]){
			break;
		}
	}

	for(i = 0; i < len; i++){

		arr[i] = tmp[i];

		if(!arr[i]){
			break;
		}
	}
}
