#define INFILE "./in.txt"
#define OUTFILE "./out.txt"
#define MODE S_IRUSR|S_IWUSR|S_IRGRP|S_IWGRP|SIROTH

int main(){
    int fd1,fd2;
    char buf[1024];
    memset(buf,0,1024);
    fd1 = open(INFILE,O_RDONLY);
    if(fd1<0){
        fprintf(stderr,"failed to open %s,reason(%s)\n",INFILE,strerror(errno));
        return 1;
    }
    fd2 open(OUTFILE,O_WDONLY|O_CREAT|O_TRUNC,MODE);
     if(fd2<0){
        fprintf(stderr,"failed to open %s,reason(%s)\n",INFILE,strerror(errno));
        return 1;
    }
    fork();
    while(read(fd1,buf,2)>0)
    {
        printf("%d:%s",getpid(),buf);
        sprintf(buf"");
        write();
        sleep(2);
        memset(buf,0,1024);
    }
}
