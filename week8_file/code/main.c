#include<stdio.h>
#include "task1_3.h"
int main(){
    char * filepath = "01.txt";
    char buffer[1024] = "this is a test";
    newFile(filepath);
    int fd = open(filepath,O_WRONLY);
    writeFile(fd,buffer);
    close(fd);
    int fd = open(filepath,O_RDONLY);
    readFile(fd,buffer);
    close(fd);
}
