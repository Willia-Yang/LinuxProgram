#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

void newFile(const char *pathname){
    int fd1 = creat(pathname,O_CREAT);
    if(fd1<0)
        printf("create error");
    else{
        printf("create success");
    }
}

void writeFile(int fd,const void * buff){
    int haswritted = write(fd,buff,sizeof(buff));
    if(haswritted<0){
        printf("write error");
    }
    else{
        printf("write success");
    }
}

void readFile(int fd,const void * buff){
    int hasread = write(fd,buff,sizeof(buff));
    if(hasread<0){
        printf("read error");
    }
    else{
        printf("read success");
        printf("the content of read:%s\n",buff);
    }
}
