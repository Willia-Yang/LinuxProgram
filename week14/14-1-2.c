# include "my.h"

void * worker(void * arg)
{
    int TTD = pthread_self();
    printf("thread -- %d:gettid return %d\n",TTD,getpid());
    printf("thread -- %d:pthread_self return %p\n",TTD,getpid());
}

void * threadfun()
{
    printf("pid = %d:worker thread is running !\n",getpid());
}
int main(){
    pthread_t tid ;
    int error = pthread_create(&tid,NULL,threadfun,NULL);
    if(error!=0)
    {
        perror("thread create failed!\n");
        return -1;
    }
    printf("master thread pid");
}
