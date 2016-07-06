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

int setup_daemon(void)
{
	pid_t pid;
	pid=fork();
	if(pid==-1)
	  ERR_EXIT("fork");
	if(pid>0)
	  exit(EXIT_SUCCESS);
	else if(pid==0)
	  setsid();
	return 0;
}

int main(void)
{
	setup_daemon();
	while(1);
	return 0;
}
