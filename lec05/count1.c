#include <stdio.h>
#define VALUE_ONE 1

int count_one(unsigned int a){

	int static numCalls = 0;
	int count = 0;
	
	while(a != 0){
	 	count += a & VALUE_ONE;
		a >>= VALUE_ONE;
	}
	
	fprintf(stderr, "Call : %d\n", numCalls);
	numCalls++;

	return count;
}

int main()
{
	int i;
	int in_a;
	fscanf(stdin, "%u", &in_a);
	fprintf(stdout, "%u \t : ", in_a);
	for(i = 31 ; i >= 0 ; i--){

		fprintf(stdout, "%d", ((in_a >>i ) &1));
		if (i % 4 == 0)
			fprintf(stdout, " ");
	}
	count_one(in_a);
	count_one(in_a);
	count_one(in_a);
	count_one(in_a);
	fprintf(stdout, ": %d \n", count_one(in_a));

}
