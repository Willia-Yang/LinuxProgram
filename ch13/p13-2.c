#include "ch13.h"
#define NUM_THREADS    4 

void Hello(void * t)     /* 线程开始函数 */
{
   pthread_t my_tid;
   my_tid = pthread_self();   /* 获得当前线程TID */
   printf("\tThread %d: my tid is %lx, Hello World!\n", t, my_tid);
}
int main ()
{
   pthread_t tid;
   int rv, t;
   for(t=0; t<NUM_THREADS; t++){
      rv = pthread_create(&tid, NULL, (void *(*)())Hello, (void*)t);
      check_error(rv, "pthread_create()" )
      printf("Created thread %lx\n", tid);
   }
   printf("Good bye\n");
   pthread_exit(NULL);     /* 终止线程 */
}
