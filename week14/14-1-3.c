#include "my.h"
#define NUM 4
void fun(void *arg){
	int *pt;
	pt = (int *)arg;
	printf("worker thread %d:tid = %p\n",(int)pt,pthread_self());
}
int main(){
	pthread_t tid[NUM];
	int ret;
	int i;
	for(i=0;i<NUMl;i++)
	for(i=0;i<NUMl;i++)
	printf("");
	for(il;i++)
}
