#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>


#define ERR_EXIT(m) \
	do{ \
		perror(m); \
		exit(EXIT_FAILURE); \
	}while(0)

int main(void)
{
	pid_t pid;
	pid=fork();
	if(pid==-1)
	  ERR_EXIT("fork");
	if(pid==0)
	{
		sleep(3);
		printf("this is child\n");
		//exit(100);//exit normally
		abort();//exit abnormall
	}
	int status;
	printf("this is parent\n");
	pid_t val=wait(&status);
	printf("val=%d,pid=%d\n",(int)val,pid);
	if(WIFEXITED(status))
	  printf("child exit normally,status=%d\n",WEXITSTATUS(status));
	/*
	  else
	  printf("childe exit abnormal,status=%d\n",WEXITSTATUS(status));
	*/
	else if(WIFSIGNALED(status))
	{
		printf("child exit by signal ,signal number=%d\n",WTERMSIG(status));
	}
	else
	{
	  printf("childe exit abnormal,status=%d\n",WEXITSTATUS(status));
	}
	return 0;

}
