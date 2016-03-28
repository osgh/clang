#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "run_len_coding.h"

#define TEST_ARR_LEN 15

int print_data(const void * data, int len);

int main(void)
{
	//test data
	unsigned char test[TEST_ARR_LEN] = {0x12, 0x12, 0x12, 0x34, 0x99, 0xee, 0xee, 0xee, 0xee, 0xff};
	
	printf("\nencode before:\n");
	print_data(test, TEST_ARR_LEN);

	//count zip data length
	int ziplen = zip_len(test, TEST_ARR_LEN);
	if(-1 == ziplen){
		printf("error:-1:function zip_len() received invalid parameters.");
		return -1;
	}
	printf("\n\nencode need %d bytes memory spaces.\n",ziplen);

	unsigned char *encode_dest = (unsigned char *)malloc(ziplen*sizeof(unsigned char));
	if(NULL == encode_dest){
		printf("there is not enough memory space.\n");
		return -1;
	}

	//encode
	int encode_len = rlc_encode(encode_dest, test, TEST_ARR_LEN);
	if(-1 == encode_len){
		printf("error:-1:function rlc_encode() received invalid parameters.");
		return -1;
	} 
	else if(-2 == encode_len){
		printf("error:-2:function expand() received invalid parameters.");
		return -1;
	}
	printf("\nencode after:\n");
	print_data(encode_dest, encode_len);

	//count extract data length
	int extractlen = extract_len(encode_dest, encode_len);
	if(-1 == extractlen){
		printf("error:-1:function zip_len() received invalid parameters.");
		return -1;
	}
	printf("\n\ndecode need %d bytes memory spaces.\n", extractlen);

	unsigned char *decode_dest = (unsigned char *)malloc(extractlen*sizeof(unsigned char));
	if(NULL == decode_dest){
		free(encode_dest);//free encode_dest memory spaces.
		printf("there is not enough memory space.\n");
		return -1;
	}

	//decode
	int decode_len = rlc_decode(decode_dest, encode_dest, encode_len);

	printf("\ndecode after:\n");
	print_data(decode_dest, decode_len);

	printf("\n\n");

	free(encode_dest);
	free(decode_dest);

	return 0;
}

int print_data(const void * data, int len)
{
	if(NULL == data || 0 == len){
		return -1;
	}

	const unsigned char *tmp = (const unsigned char *)data;

	int i = 0;
	for (; i< len; i++)
	{
		printf("0x%x ", *(tmp++));
	}

	return 0;
}
