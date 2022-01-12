#include <stdio.h>

int sumArray3(int *a, int sum)
{	
	sum = *a;
	a++;	
	sum += *a;
	a++;
	sum += *a;
	fprintf(stdout, "%d : %lld %llx\n", sum, &sum, &sum);
	return a[3];
}
int main()
{
	int a = 100;
	int b = 200;
	int c = 999;
	const int arr[4] = {100, 200, 300, 400};
	int *parr;
	parr = arr;
	parr++;
	fprintf(stdout, "%d : %lld %lld\n", *parr, parr, arr);
	c = sumArray3(arr, b);
	fprintf(stdout, "%d : %lld %llx\n", b, &b, &b);
	fprintf(stdout, "%d : %lld %llx\n", arr, arr, arr);
	fprintf(stdout, "%d : %lld %llx\n", *arr, *arr, *arr);
	fprintf(stdout, "%d : %lld %llx\n", &arr, &arr, &arr);
	fprintf(stdout, "%d : %lld %llx\n", arr[2], &arr[2], &arr[2]);
	fprintf(stdout, "%d : %lld %llx\n", arr[3], &arr[3], &arr[3]);
}
