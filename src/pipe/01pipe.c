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

int main(void)
{
	int pipefd[2];
	if(pipe(pipefd)<0)
	  ERR_EXIT("pipe error");
	pid_t pid;
	pid=fork();
	if(pid==-1)
	  ERR_EXIT("fork error");
	if(pid==0)
	{
		close(pipefd[0]);
		write(pipefd[1],"hello",5);
		close(pipefd[1]);
		exit(EXIT_SUCCESS);
	}
	char buf[1024]={0};
	close(pipefd[1]);
	read(pipefd[0],buf,1024);
	printf("buf=%s\n",buf);
	close(pipefd[0]);
	return 0;
}
