#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define ERR_EXIT(m) \
	do{ \
		perror(m); \
		exit(EXIT_FAILURE); \
	}while(0);

int main(void)
{
	close(0);
	open("Makefile",O_RDONLY);
	close(1);
	open("Makefile.back",O_WRONLY | O_CREAT | O_TRUNC,0644);
	if(execlp("cat","cat",NULL)<0)
	  ERR_EXIT("execlp error");
	return 0;
}
