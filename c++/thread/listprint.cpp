#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
 #include <unistd.h>

char l1[]={'a','b','c','d','e'};
char l2[]={'l','m','n','o','p'};
char l3[]={'u','v','w','x','y'};
int count1, count2, count3;

#define NTHREADS	3

pthread_mutex_t	mutexes[NTHREADS] = {PTHREAD_MUTEX_INITIALIZER, PTHREAD_MUTEX_INITIALIZER,PTHREAD_MUTEX_INITIALIZER};
pthread_cond_t	conditions[NTHREADS] = {PTHREAD_COND_INITIALIZER,PTHREAD_COND_INITIALIZER,PTHREAD_COND_INITIALIZER};

typedef struct{
	int	tid;
	int 	printed;
	int	size;
	char	*buffer;
}thread_data;

void* thread(void *arg)
{
	thread_data *data = (thread_data*)arg;
	int tid 	= data->tid;
	int printed	= 0;
	int size	= data->size;

	while(1)
	{
		pthread_mutex_lock(&mutexes[tid]);
		pthread_cond_wait(&conditions[tid],&mutexes[tid]);
		fprintf(stderr,"thread: %d item: %c\n",tid, 
				data->buffer[printed%size]);
		printed++;
		data->printed=printed;
		pthread_mutex_unlock(&mutexes[tid]);

		usleep(1);	//	why is it needed?

		pthread_mutex_lock(&mutexes[(tid+1)%NTHREADS]);
		pthread_cond_signal(&conditions[ (tid+1)%NTHREADS ]);
		pthread_mutex_unlock(&mutexes[(tid+1)%NTHREADS]);
	}
	return NULL;
}

void init_thread_data(thread_data *data, int tid, int size, char *buffer)
{
	data->tid 	=	tid;
	data->size	=	size;
	data->buffer	=	buffer;
	data->printed	=	0;
}

int main(int argc, char *argv[])
{
	thread_data data1, data2, data3;
	init_thread_data(&data1, 0, sizeof(l1), l1);
	init_thread_data(&data2, 1, sizeof(l2), l2);
	init_thread_data(&data3, 2, sizeof(l3), l3);

	pthread_t t1, t2, t3;

	pthread_create(&t1, 0, thread, &data1);
	pthread_create(&t2, 0, thread, &data2);
	pthread_create(&t3, 0, thread, &data3);

	usleep(2);


	pthread_mutex_lock(&mutexes[0]);
	pthread_cond_signal(&conditions[0]);
	pthread_mutex_unlock(&mutexes[0]);

	pthread_join(t1,0);
	pthread_join(t2,0);
	pthread_join(t3,0);
	return 0;

}
