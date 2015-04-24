#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <stdlib.h>
#include <cstring>
#include <unistd.h>

#define TRUE 1
#define FALSE 0

#define MAX 1024
char n[MAX];

int char_read = 0;

pthread_mutex_t lock= PTHREAD_MUTEX_INITIALIZER;
int string_read=FALSE;

pthread_cond_t cond;

void * read1(void* arg)
{
	while(1)
	{
		while(string_read);
		  
		pthread_mutex_lock(&lock);
		
		char helpstr[] = "Enter a string:";
		write(1,helpstr,strlen(helpstr));
		
		char_read = read(0,n,MAX);
    string_read=TRUE;
		
		pthread_cond_signal(&cond);
		pthread_mutex_unlock(&lock);
		if(n == 0)
			pthread_exit(0);
	}
}

void * write1(void* arg)
{
	while(1)
	{
		sleep(5);
		pthread_mutex_lock(&lock);
		
		while(not string_read)
			pthread_cond_wait(&cond,&lock);

		char helpstr[] = "String entered is:";
		write(1,helpstr,strlen(helpstr));
		
		write(1,n,char_read);

		string_read=FALSE;
		pthread_mutex_unlock(&lock);
	}
	pthread_exit(NULL);
}

int main()
{
	pthread_t tr,tw;

	pthread_create(&tr,NULL,read1,NULL);
	pthread_create(&tw,NULL,write1,NULL);

	pthread_join(tr,NULL);
	pthread_join(tw,NULL);
	
	pthread_exit(NULL);
}

