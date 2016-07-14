#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/time.h>

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
	if(signal(SIGALRM,newhandler)==SIG_ERR)
	  ERR_EXIT("signal");
	struct itimerval itime;
	struct timeval it_iterval={2,0};
	struct timeval it_value={2.0};
	itime.it_interval=it_iterval;
	itime.it_value=it_value;
	if(setitimer(ITIMER_REAL,&itime,NULL)<0)
	  ERR_EXIT("setitimer error");

	for(;;)
	  pause();
	return 0;
}
