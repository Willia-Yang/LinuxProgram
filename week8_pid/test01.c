#inlcude<stdio.h>
int main(int argc,char *argv[],char *env[]){
    extern char **environ;
    int i = 0;
    for (;env[i];i++){
        printf("%s\n",env[i]);
    }
    int j = 0;
    for (;envirom[j];j++){
        printf("%s\n",environ[j]);
    } 
    printf("%s\n",getenv("PATH"));
    return 0;
}
