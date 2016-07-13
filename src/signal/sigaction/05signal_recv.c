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
	if(sig==SIGINT||sig==SIGRTMIN)
	  printf("recv a sig ,which number=%d\n",sig);
	else if(sig==SIGUSR1)
	{
		sigset_t set;
		sigemptyset(&set);
		sigaddset(&set,SIGINT);
		sigaddset(&set,SIGRTMIN);
		if(sigprocmask(SIG_UNBLOCK,&set,NULL)<0)
		  ERR_EXIT("sigprocmask error");
	}
}

int main(void)
{
	
	struct sigaction act;
	act.sa_handler=newhandler;
	sigemptyset(&act.sa_mask);
	act.sa_flags=0;

	sigset_t set;
	sigemptyset(&set);
	sigaddset(&set,SIGINT);
	sigaddset(&set,SIGRTMIN);
	sigprocmask(SIG_BLOCK,&set,NULL);

	if(sigaction(SIGINT,&act,NULL)<0)
	  ERR_EXIT("sigaction error");
	
	if(sigaction(SIGRTMIN,&act,NULL)<0)
	  ERR_EXIT("sigaction error");

	if(sigaction(SIGUSR1,&act,NULL)<0)
	  ERR_EXIT("sigaction error");
	for(;;)
	  pause();
	return 0;
}
