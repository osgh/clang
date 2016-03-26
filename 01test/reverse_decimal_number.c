#include <stdio.h>

int num_len(int n);
int reverse_decimal_number(int number);

int main()
{
	int test = 2147483641;

	printf("test decimal number:%d\n", test);

	int val = reverse_decimal_number(test);
	
	if(val >= 0){
		printf("Decimal number reversed:%d\n", val);
	} else if(val == -1){
		printf("error:-1: Input value less than zero(0).\n");
	} else if(val == -2){
		printf("error:-2: Overflow:result too large for integer value.\n");
	}

	return 0;
}

int reverse_decimal_number(int number)
{
	/* integer value less than 0 */
	if(number < 0){
		return -1;
	}

	long ret = 0, tmp = 0;
	int i = 0, j = 0, digit = 0;
	int len = num_len(number);
	
	do{
		digit = number%10;

#ifdef DEBUG
		printf("digit:%d\tlen:%d\n", digit, len);
#endif
		tmp = digit;
		for(j = len--; j > 1; j--){
			tmp *= 10;
		}

		ret += tmp;

		i++;

	}while (number = number/10);

#ifdef DEBUG
		printf("long integer number value:%ld\n", ret);
#endif

	/* integer value overflow */
	if(ret > (~(0x1<<(sizeof(int)*8-1)))){
		return -2;
	}

	return ret;
}

int num_len(int n)
{
	int len = 0;

	do{
		len++;
	}while (n /= 10);
	
	return len;
}

