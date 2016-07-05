#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>


#define ERR_EXIT(m) \
	do { \
		perror(m); \
		exit(EXIT_FAILURE); \
	}while(0)

int main(void)
{
	printf("before fork ,pid=%d\n",getpid());
	pid_t pid;
	pid=fork();
	if(pid==-1)
	  ERR_EXIT("fork");
	if(pid>0)
	{
		printf("this is parent,pid=%d,and childpid=%d\n",(int)getpid(),(int)pid);
		//sleep(1);
	}
	else if(pid==0)
	{
		sleep(2);
		printf("this is child,pid=%d,parentpid=%d\n",(int)getpid(),(int)getppid());
	}
	return 0;
}
