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

int main(void)
{
	struct itimerval itime;
	struct timeval it_iterval={2,0};
	struct timeval it_value={2.0};
	itime.it_interval=it_iterval;
	itime.it_value=it_value;
	if(setitimer(ITIMER_REAL,&itime,NULL)<0)
	  ERR_EXIT("setitimer error");
	int i;
	for(i=0;i<10000;i++)
	  ;
	struct itimerval oitime;
	if(setitimer(ITIMER_REAL,&itime,&oitime)<0)
	  ERR_EXIT("setitimer error");
	printf("between time=%d秒%d微秒,left time=%d秒%d微秒\n",(int)oitime.it_interval.tv_sec,(int)oitime.it_interval.tv_usec,(int)oitime.it_value.tv_sec,(int)oitime.it_value.tv_usec);
	return 0;
}
