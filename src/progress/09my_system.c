#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

#define ERR_EXIT(m) \
	do { \
		perror(m); \
		exit(EXIT_FAILURE); \
	}while(0)

int my_system(const char* command)
{
	pid_t pid;
	int status;
	pid=fork();
	if(pid==-1)
	  return -1;
	if(pid==0)
	{
		status=1;
		execl("/bin/sh","sh","-c",command,NULL);
		exit(127);
	}
	int ret=waitpid(pid,&status,0);
	if(ret==-1)
	  status=-1;
	return status;
}


int main(void)
{
	my_system("ls -l");

	return 0;
}
