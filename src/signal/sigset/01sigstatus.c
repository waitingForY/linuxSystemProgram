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
	if(sig==SIGINT)
	  printf("recv a sig,which number=%d\n",sig);
	else if(sig==SIGQUIT)
	{
		sigset_t uset;
		sigemptyset(&uset);
		sigaddset(&uset,SIGINT);
		sigprocmask(SIG_UNBLOCK,&uset,NULL);
	}
}
void printsigset(sigset_t *set)
{
	int i;
	for(i=1;i<NSIG;++i)
	{
		if(sigismember(set,i))
		  putchar('1');
		else
		  putchar('0');
	}
	printf("\n");
}
int main(void)
{
	sigset_t pset;
	sigset_t bset;
	sigemptyset(&bset);
	sigaddset(&bset,SIGINT);
	if(signal(SIGINT,newhandler)==SIG_ERR)
	  ERR_EXIT("signal");
	if(signal(SIGQUIT,newhandler)==SIG_ERR)
	  ERR_EXIT("signal");
	sigprocmask(SIG_BLOCK,&bset,NULL);
	for(;;)
	{
		sigpending(&pset);
		printsigset(&pset);
		sleep(1);
	}
	return 0;
}
