#include <pthread.h>
#include <stdio.h>

		pthread_mutex_t mut;
		pthread_cond_t con;

		int iseven = 1;

void *odd(void* param)
{

	for(int i =1;i<100;i+=2) 
	{
		pthread_mutex_lock(&mut);
		while(iseven !=0)
			pthread_cond_wait(&con,&mut); 
		printf(" odd :%d\n", i);
		iseven = 1;
		pthread_cond_signal(&con);
		pthread_mutex_unlock(&mut);
	}
	return NULL;

}

void *even(void* param)
{

	for(int i =0;i<=100;i+=2) 
	{
		pthread_mutex_lock(&mut);
		while(iseven !=1)
			pthread_cond_wait(&con,&mut); 
		printf(" even :%d\n", i);
		iseven = 0;
		pthread_cond_signal(&con);
		pthread_mutex_unlock(&mut);
	}
	return NULL;
}


		int main()
		{

			pthread_mutex_init(&mut, NULL);
			pthread_cond_init(&con, NULL);
	
			pthread_t thread[2];

			pthread_create(&thread[0], 0, even, NULL);
			pthread_create(&thread[1], 0, odd, NULL);

			pthread_join(thread[0], 0);
			pthread_join(thread[1], 0);
			return 0;
		}
