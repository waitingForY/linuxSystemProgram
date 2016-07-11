#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <signal.h>
#include <sys/types.h>

#define ERR_EXIT(m) \
	do{ \
		perror(m); \
		exit(EXIT_FAILURE); \
	}while(0);

void newhandler(int sig)
{
	printf("recv a sig,which number=%d\n",sig);
}

int main(void)
{
	if(signal(SIGUSR1,newhandler)==SIG_ERR)
	  ERR_EXIT("signal");
	pid_t pid;
	pid=fork();
	if(pid==-1)
	  ERR_EXIT("fork error");
	if(pid==0)
	{
		if(kill(getppid(),SIGUSR1)==-1)
		  ERR_EXIT("kill error");
	}
	int n=5;
	do
	{
		n=sleep(n);
	}while(n>0);

	return 0;
}
