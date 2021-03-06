#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/socket.h>
void error_handling(char *message);

int main(int argc,char *argv[]){
    int tcp_sock,udp_sock;
    int sock_type;
    socklen_t optlen;
    int state;

    optlen=sizeof(sock_type);
    //printf("opelen: %d",optlen);
    tcp_sock=socket(PF_INET,SOCK_STREAM,0);//生成TCP套接字
    udp_sock=socket(PF_INET,SOCK_DGRAM,0);//生成UDP套接字
    printf("SOCK_STREAM: %d \n",SOCK_STREAM);//输出传入的SOCK_STREAM,SOCK_DGRAM
    printf("SOCK_DGRAM: %d \n",SOCK_DGRAM);

    state=getsockopt(tcp_sock,SOL_SOCKET,SO_TYPE,(void*)&sock_type,&optlen);
    if(state)
        error_handling("getsockopt() error!");
    printf("Socket type two: %d \n",sock_type);
    return 0;
}

void error_handling(char *message){
    fputs(message,stderr);
    fputc('\n',stderr);
    exit(1);
}