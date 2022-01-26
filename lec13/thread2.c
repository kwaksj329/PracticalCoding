#include <pthread.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>


int bbb = 0; 

void fn_s()
{
    static int a = 0; 
    printf("== %d %d ==",a++, bbb++);
}


void *run (void *arg)
{
    printf("Hello world of POSIX threads.%d\n", (int)(0) );
    for (int i = 0; i < 10; i++)
	{
		sleep(1); 
		fn_s(); 
	}
    return 0;

}

int main()
{
	char bufff[10];
    	setvbuf(stdout, bufff,  _IOFBF,  10);
	//pthread_t thread1;
	int result1;
	//pthread_create(&thread1, NULL, run, NULL );
	run((void *) 0); 
	//pthread_join(thread1, (void **) &result1);
	printf("Thread return %d at the end\n", result1);
}

