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

typedef struct
{
	int x;
	int y;
}TEST;


TEST data;
void unsalf_func()
{
	printf("data.x=%d,data.y=%d\n",data.x,data.y);
}
void newhandler(int sig)
{
	unsalf_func();
	alarm(1);
}
int main(void)
{
	TEST zeros={0,0};
	TEST ones={1,1};
	data=zeros;
	if(signal(SIGALRM,newhandler)==SIG_ERR)
	  ERR_EXIT("signal");
	alarm(1);
	for(;;)
	{
		data=zeros;
		data=ones;
	}
	return 0;
}
