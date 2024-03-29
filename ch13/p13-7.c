#include "ch13.h"
#define SIZE 100
int a[SIZE],b[SIZE];
int max;
pthread_mutex_t mtx = PTHREAD_MUTEX_INITIALIZER;

void max_fun(int *arg)    /* 计算max(max, arg[]) */
{
   int * ap=arg;
   int rv, i, l_max;
   for (i=1; i<SIZE; i++){ // 找出数组ap中的最大值
      if (ap[i] > l_max) 
         l_max = ap[i];
   }
   /* 计算max(L_max, max),需互斥操作 */
   rv = pthread_mutex_lock(&mtx);      // 获得互斥变量
   check_error(rv, "mutex_lock ");
   if (l_max > max)
      max = l_max;
   rv = pthread_mutex_unlock(&mtx);   // 释放互斥变量
   check_error(rv, "mutex_unlock ");
   pthread_exit(NULL);       
}

int main(void)
{
   pthread_t tid1,tid2;    // 线程标识
   int i, rv;
   
   for (i=1; i<SIZE; i++){ // 生成数组元素的数据
      a[i]=rand();
      b[i]=rand();
   }
   /* 创建2个线程执行函数max_fun()分别处理数组a和b */
   rv = pthread_create(&tid1, NULL, (void*(*)())max_fun, a);
   check_error(rv, "pthread_create: tid1");
   rv = pthread_create(&tid2, NULL, (void*(*)())max_fun, b);
   check_error(rv, "pthread_create: tid2");
   /* 等待2个线程结束 */
   pthread_join(tid1, NULL);
   pthread_join(tid2, NULL);
   printf ("max value = %d\n", max);
   exit(0);
}
