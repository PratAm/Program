#include <pthread.h>
#include <cstdio>
#include <cstdlib>
#include <unistd.h>
#define NUM_THREADS     5

void fprintPt(FILE *f, pthread_t pt) {
	unsigned char *ptc = (unsigned char*)(void*)(&pt);
	fprintf(f, "0x");
	for (size_t i=0; i<sizeof(pt); i++) {
		fprintf(f, "%02x\n", (unsigned)(ptc[i]));
	}
}

void *PrintHello(void *threadid)
{
   long tid;
   tid = (pthread_t)threadid;
   printf("Hello World! It's me, thread #%ld! and threadid:%d\n", tid,getpid());
   pthread_exit(NULL);
	 while(1);
}

int main (int argc, char *argv[])
{
   pthread_t threads[NUM_THREADS];
   int rc;

   long t;
   for(t=0; t<NUM_THREADS; t++){
      printf("In main: threadid: %d creating thread %ld\n", getpid(),t);
      rc = pthread_create(&threads[t], NULL, PrintHello, (void *)t);
      if (rc){
         printf("ERROR; return code from pthread_create() is %d\n", rc);
         exit(-1);
      }
   }
	 while(1);
   pthread_exit(NULL);
}
