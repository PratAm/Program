#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>
    
#define NUM_MSGS 65536

typedef struct msg {
    struct msg *m_next;
    char content[36];
} msg;

msg *workq;

pthread_cond_t qready = PTHREAD_COND_INITIALIZER;
pthread_mutex_t qlock = PTHREAD_MUTEX_INITIALIZER;

void process_msg(void){
    msg *mp;

    for (;;) {
        pthread_mutex_lock(&qlock);
        // Wake up by the another thread
        while (workq == NULL)
            pthread_cond_wait(&qready, &qlock);
        mp = workq;
        workq = mp->m_next;
        pthread_mutex_unlock(&qlock);

        /* now process the second part of your work */
        printf("Message from anther thread: %s\n", mp->content);
        free(mp);
    }
}

void enqueue_msg(msg *mp){
    pthread_mutex_lock(&qlock);
    mp->m_next = workq;
    workq = mp;
    pthread_mutex_unlock(&qlock);
    pthread_cond_signal(&qready);
}

void * thr_fn1(void *arg){
    msg *new_msg;

    printf("thread 1: ID is %lu\n", (unsigned long) pthread_self());
    for (int i=0 ; i < NUM_MSGS ; i++){
        // Do the first part of work here
        sleep(1);

        // Send a message to wake the other thread
        new_msg = (struct msg *) malloc(sizeof(msg));
        memset(new_msg,0,sizeof(msg));
        sprintf(new_msg->content, "Message %d from Thread 1\n", i);
        enqueue_msg(new_msg);
    }
    pthread_exit((void *)0);
}

void * thr_fn2(void *arg){
    printf("thread 2: ID is %lu\n", (unsigned long) pthread_self());
    process_msg();
    pthread_exit((void *)0);
}

void * err_exit(int err, char *err_msg){
    printf("Error: %d, Message: %s\n", err, err_msg);
    exit(err);
}

int main(void){
    int err;
    pthread_t tid1, tid2;

    workq=NULL;
    err = pthread_create(&tid1, NULL, thr_fn1, NULL);
    if (err != 0)
        err_exit(err, "can't create thread 1");

    printf("parent starting second thread\n");
    err = pthread_create(&tid2, NULL, thr_fn2, NULL);
    if (err != 0)
        err_exit(err, "can't create thread 2");

    // the process terminates when thread 1 finishes.
    err = pthread_join(tid1, NULL);
    if (err != 0)
        err_exit(err, "can't join with thread 1");
    sleep(1);
    printf("End.\n");
    exit(0);
}
