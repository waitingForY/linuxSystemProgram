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
		dup2(pipefd[1],fileno(stdout));
		close(pipefd[1]);
		close(pipefd[0]);
		if(execlp("ls","ls",NULL)<0)
		  ERR_EXIT("execlp error");

	}
	dup2(pipefd[0],fileno(stdin));
	close(pipefd[0]);
	close(pipefd[1]);
	if(execlp("wc","wc","-w",NULL)<0)
	  ERR_EXIT("execlp error");
	return 0;
}
