#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>


#define ERR_EXIT(m) \
	do { \
		perror(m); \
		exit(EXIT_FAILURE); \
	}while(0)

int main(void)
{
	printf("main entering...\n");
	printf("pid=%d\n",getpid());
	//int ret=execl("/bin/ls","ls","-l",NULL);
	int ret=execlp("./test","test",NULL);
	if(ret==-1)
	  perror("execl error");
	printf("main exiting...\n");
	return 0;
}
