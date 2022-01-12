#include <stdio.h>

void add(int *a, int *b, int *c)
{
	*c = *a + *b;
}

int main()
{
	const int a = 100;
	int b = 200;
	long long c = 999;
	// int * = long long 
	
	fprintf(stdout, "%d : %lld %llx\n", a, &a, &a);
	fprintf(stdout, "%d : %lld %llx\n", b, &b, &b);
	add(&a, &b, &c);
	fprintf(stdout, "%d : %lld %llx\n", c, &c, &c);
	fprintf(stdout, "%d : %lld %llx\n", c, (&c)+1, &c+1);
	//fprintf(stdout, "%d : %lld %llx\n", c, ((void *)(&c))+1, &c+1);
	//원래는 long long 포인터인데 void 포인터로 바껴서 1씩 증가됨 (char 포인터도 1씩 증가)
	fprintf(stdout, "%d : %lld %llx\n", c, (&c)+2, &c+2);
}
