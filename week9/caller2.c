#include "my.h"
int main(){
    int ret;
    char * arg[]={"./test1","123","456"};
    printf("caller1:pid=%d,ppid = %d\n",getpid(),getppid()");
    execl("/home/rlk/test1","./test1","123","456",NULL);
    //execv("/home/rlk/test1",arg,NULL);
    //execlp("test1","./test1","123","456",NULL);
    printf("after calling\n");
    sleep(1);
    return 0;
}
