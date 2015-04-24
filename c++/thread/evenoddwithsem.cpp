#include <pthread.h>
#include <stdio.h>
#include <semaphore.h>
// this is posix semaphores which are binary in nature
sem_t even;
sem_t odd;

void *printodd(void* param)
{

	for(int i =1;i<100;i+=2) 
	{
		sem_wait(&odd);
		printf(" odd :%d\n", i);
		sem_post(&even);

	}
	return NULL;

}

void *printeven(void* param)
{

	for(int i =0;i<=100;i+=2) 
	{
		sem_wait(&even);
		printf(" even :%d\n", i);
		sem_post(&odd);
	}
	return NULL;
}


		int main()
		{

			sem_init(&even, 0,1); // initial value 1
			sem_init(&odd, 0,0); // initial value 0
	
			pthread_t thread[2];

			pthread_create(&thread[0], 0, printeven, NULL);
			pthread_create(&thread[1], 0, printodd, NULL);

			pthread_join(thread[0], 0);
			pthread_join(thread[1], 0);
			return 0;
		}
