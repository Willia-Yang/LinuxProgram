#include "my.h"

int main(){
    int a = 0;
    pid_t pid;
    printf("pid = %d: %d",getpid(),a);
    pid = vfork();
    if(pid<0){
        perror("vfork failed!\n");
        exit(-1);
    }
    else{
        printf("pid = %d: %d",getpid(),a);
    }
    return 0;

}
