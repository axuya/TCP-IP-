#include<stdio.h>
#include<unistd.h>
#define BUF_SIZE 30

int main(int argc,char *argv[]){
    int fds[2];
    char str[] = "Who are you?";
    char buf[BUF_SIZE];
    pid_t pid;

    pipe(fds);//调用pipe函数创建管道，fds中保存I/O的文件描述符
    pid = fork();
    if(pid==0){
        write(fds[1],str,sizeof(str));
    }
    else{
        read(fds[0],buf,BUF_SIZE);//filedes[1] 管道出口，通过管道传输数据时使用的文件描述符
        puts(buf);
    }
    return 0;
}