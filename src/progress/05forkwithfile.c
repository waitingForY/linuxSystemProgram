#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


#define ERR_EXIT(m) \
	do { \
		perror(m); \
		exit(EXIT_FAILURE); \
	}while(0)

int main(void)
{
	printf("before fork ,pid=%d\n",getpid());
	int fd;
	fd=open("test.txt",O_RDWR|O_CREAT);
	if(fd==-1)
	  ERR_EXIT("open file error");
	
	pid_t pid;
	pid=fork();
	if(pid==-1)
	  ERR_EXIT("fork");
	if(pid>0)
	{
		write(fd,"parent",6);
		printf("this is parent,pid=%d,and childpid=%d\n",(int)getpid(),(int)pid);
		//sleep(1);
	}
	else if(pid==0)
	{
		write(fd,"child",5);
		printf("this is child,pid=%d,parentpid=%d\n",(int)getpid(),(int)getppid());
	}
	return 0;
}
