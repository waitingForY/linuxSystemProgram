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
	struct sigaction act;
	act.sa_handler=newhandler;
	sigemptyset(&act.sa_mask);
	act.sa_flags=0;
	if(sigaction(SIGINT,&act,NULL)<0)
	  ERR_EXIT("sigaction error");
	for(;;)
	  pause();
	return 0;
}
