#include <stdio.h>

void add(int *a, int *b, int *c)
{ *c = *a + *b;}

void sub(int *a, int *b, int *c)
{ *c = *a - *b;}

void div(int *a, int *b, int *c)
{ *c = (*a) / (*b);}

void mul(int *a, int *b, int *c)
{ *c = (*a) * (*b);}


int main()
{
	int a = 100;
	int b = 200;
	int c = 0;
	char ch;
	int op = 0;
	scanf("%d %c %d", &a, &ch, &b);

	void (*fp[4])(int *, int *, int *) = {add, sub, mul, div};

	//int const *p = &a;
	//int * const q = &a; // 둘의 차이 알아두기!
	
	switch(ch){
		case '+':
			op = 0;
			break;
		case '-':
			op = 1;
			break;
		case '*':
			op = 2;
			break;
		case '/':
			op = 3;
			break;
	}

	fprintf(stdout, "a, b, c: %d %d %d\n", a, b, c);
	fp[op](&a, &b, &c);
	fprintf(stdout, "a, b, c: %d %d %d\n", a, b, c);
	fprintf(stdout, "fp %lld %lld %lld %lld\n", add, sub, mul, div);
}
