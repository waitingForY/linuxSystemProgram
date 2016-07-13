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


void newhandler(int sig, siginfo_t *info, void *ctx)
{
	printf("recv a sig ,which number=%d,data=%d,(data=%d)\n",sig,info->si_value.sival_int,info->si_int);
}


int main(void)
{
	
	struct sigaction act;
	act.sa_sigaction=newhandler;
	sigemptyset(&act.sa_mask);
	act.sa_flags=SA_SIGINFO;
	if(sigaction(SIGINT,&act,NULL)<0)
	  ERR_EXIT("sigaction error");
	
	for(;;)
	  pause();
	return 0;
}
