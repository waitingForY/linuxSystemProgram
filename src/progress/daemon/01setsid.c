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

int setup_daemon(void)
{
	pid_t pid;
	pid=fork();
	if(pid==-1)
	  ERR_EXIT("fork");
	if(pid>0)
	  exit(EXIT_SUCCESS);
	else if(pid==0)
	{
		//创建一个会话期；
		setsid();
		//更改当前的工作目录：
		chdir("/");
		//重定向0,1,2三个标准io；
		int i;
		for(i=0;i<3;i++)
		{
			close(i);
		}
		int ret=open("/dev/null",O_RDWR);
		if(ret==-1)
		  ERR_EXIT("open");
		dup(0);
		dup(0);
	}
	return 0;
}

int main(void)
{
	setup_daemon();
	printf("hello i am daemon\n");
	while(1);
	return 0;
}
