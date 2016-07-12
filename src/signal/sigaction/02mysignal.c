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
typedef void (*sighandler_t)(int);

void newhandler(int sig)
{
	printf("recv a sig,which number=%d\n",sig);
}

sighandler_t my_signal(int sig,sighandler_t handler)
{
	struct sigaction act;
	struct sigaction oldact;
	act.sa_handler=handler;
	sigemptyset(&act.sa_mask);
	act.sa_flags=0;
	if(sigaction(sig,&act,&oldact)<0)
	  return SIG_ERR;
	return oldact.sa_handler;
}
int main(void)
{
	sighandler_t oldhandler;
	oldhandler=my_signal(SIGINT,newhandler);
	if(oldhandler==SIG_ERR)
	  ERR_EXIT("my_signal error");
	while(getchar()!='\n')
	  ;
	if(my_signal(SIGINT,oldhandler)==SIG_ERR)
	  ERR_EXIT("my_signal error");
	for(;;)
	  pause();
	return 0;
}
