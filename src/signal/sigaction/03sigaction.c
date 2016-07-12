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
	printf("recv a SIGINT,which number=%d\n",sig);
	sleep(5);
}

int main(void)
{
	
	struct sigaction act;
	act.sa_handler=newhandler;
	sigemptyset(&act.sa_mask);
	sigaddset(&act.sa_mask,SIGQUIT);
	act.sa_flags=0;
	if(sigaction(SIGINT,&act,NULL)<0)
	  ERR_EXIT("sigaction error");
	
	//if(signal(SIGINT,newhandler)==SIG_ERR)
	//  ERR_EXIT("signal error");

	for(;;)
	  pause();
	return 0;
}
