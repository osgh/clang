#include <stdio.h>

void findmax(int s[], int t, int *k)
{
	int tmp = s[0], pos = 0;

	for(; t >= 0; t--){
		if(tmp < s[t]){
			tmp = s[t];
			pos = t;
		}
	}

	*k = pos;
}

int main()
{
	int a[10] = {12,23,45,56,78,89,11,22}, k;
	findmax(a, 10, &k);
	printf("最大元素为%d，其下标值为%d\n", a[k], k);
	return 0;
}