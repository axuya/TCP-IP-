#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
void error_handling(char* message);

int main(void){
	int fb;
	char buf[]="Let's go!\n";

	fb=open("data.txt",O_CREAT|O_WRONLY|O_TRUNC);
	if(fb==-1)
		error_handling("open() error!");
	printf("file descriptor: %d \n",fb);

	if(write(fb,buf,sizeof(buf))==-1)
		error_handling("write() error!");
	close(fb);
	return 0;
}
void error_handling(char* message){
	fputs(message,stderr);
	fputc('\n',stderr);
	exit(1);
}
