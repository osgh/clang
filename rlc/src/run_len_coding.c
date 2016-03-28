#include <stdio.h>

#include "run_len_coding.h"

/* function declarations.*/

int expand(unsigned char **dest, unsigned char val, int n);


/* function implementation */

int rlc_encode(void *dest, const void *src, int n)
{
	if(NULL == dest || NULL == src || 0 == n || dest == src){
		return -1;
	}
	
	unsigned char *ucp_dest = (unsigned char *)dest;
	const unsigned char *ucp_src  = (const unsigned char *)src;

	int i = 0, len = 0;
	unsigned char tmp = ucp_src[0];
	unsigned char counter = 1;

	for(i = 1; i < n; i++){

		if(tmp == ucp_src[i]){
			counter++;
		}
		else{

			ucp_dest[len++] = tmp;
			ucp_dest[len++] = counter;

			tmp = ucp_src[i];
			counter = 1;
		}
	}

	ucp_dest[len++] = tmp;
	ucp_dest[len++] = counter;

	return len;
	
}


int rlc_decode(void *dest, const void *src, int n)
{
	if(NULL == dest || NULL == src || 0 == n || dest == src){
		return -1;
	}

	unsigned char *ucp_dest = (unsigned char *)dest;
	const unsigned char *ucp_src  = (const unsigned char *)src;

	int i = 0, len = 0, counter = 0;

	for(i = 0; i < n; i++){

		if(!(i&1)){

			counter = ucp_src[i+1];
			len += counter;

			/* invalid input parameters */
			if(-1 == expand(&ucp_dest, ucp_src[i], counter)){
				return -2;
			}
		}
	}

	return len;
}


int zip_len(const void *data, int n)
{
	if(NULL == data || 0 == n){
		return -1;
	}
	
	const unsigned char *ucp_data  = (const unsigned char *)data;

	int i = 0, len = 1;
	unsigned char tmp = ucp_data[0];

	for(i = 1; i < n; i++){

		if(tmp^ucp_data[i]){
			tmp = ucp_data[i];
			len++;
		}
	}

	return len<<1;
	
}


int extract_len(const void *data, int n)
{
	if(NULL == data || 0 == n){
		return -1;
	}

	const unsigned char *ucp_data  = (const unsigned char *)data;

	int i = 0, len = 0;

	for(i = 0; i < n; i++){

		if(i&1){
			len += ucp_data[i];
		}
	}

	return len;
}


int expand(unsigned char **dest, unsigned char val, int n)
{
	if(NULL == dest || 0 == n){
		return -1;
	}

	int i = 0;

	for(i = 0; i < n; i++){
		*((*dest)++) = val;
	}
	return 0;
}
