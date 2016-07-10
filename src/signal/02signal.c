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
	__sighandler_t oldhander;
	oldhander=signal(SIGINT,newhandler);
	if(oldhander==SIG_ERR)
	  ERR_EXIT("signal error");
	while(getchar()!='\n')
	  ;
	if(signal(SIGINT,oldhander)==SIG_ERR)
	  ERR_EXIT("signal error");
	for(;;)
	  ;

	return 0;
}
