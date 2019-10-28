#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

void newFile(const char *pathname);

void writeFile(int fd,const void * buff);

void readFile(int fd,const void * buff);
