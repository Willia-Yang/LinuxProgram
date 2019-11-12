#include "my.h"

static void fun1(void)
{
    printf("invoked callbackfun!\n");
}

int main(){
    atexit(fun1);
    FILE *fp;
    char buf[]="buffer data!";
    if((fp=fopen("test.dat","w+"))==NULL){
        perror("create file failed!\n");
        exit(-1);
    }
    if(fputs(buf,fp)==EOF){
        perror("ffputs file failed");
        exit(-1);
    }
    printf("hell0     ");
    exit(0);
}
