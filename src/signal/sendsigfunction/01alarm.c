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
	alarm(1);
}

int main(void)
{
	//安装一个SIGALRM信号
	if(signal(SIGALRM,newhandler)==SIG_ERR)
	  ERR_EXIT("signal");
	alarm(1);
	for(;;)
	  pause();
	return 0;
}
