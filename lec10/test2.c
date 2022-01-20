#include <stdio.h>

int fxMul1(int a, int b)
{
	return a * b;	
}

int fxMul2(int a, int b)
{
	return (int)((long long) a * (long long) b);
}

int main()
{
	long long i=0;
	int ia, ib, ic, ic2;
	float fa;
	//fscanf(stdin, "%d %d", &ia, &ib);
	for(i = 0; i < (long long )256 * 256 * 256 * 256 ; i += 25)
	{
		ic = fxMul1(i, i);
	}
	for(i = 0; i < (long long )256 * 256 * 256 * 256 ; i += 5)
	{
		ic = fxMul2(i, i);
	}
}
