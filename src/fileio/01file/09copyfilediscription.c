#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <error.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


#define ERR_EXIT(m) \
	do{ \
		perror(m); \
		exit(EXIT_FAILURE); \
	}while(0)

int main(void)
{
	int fd;
	fd=open("test.txt",O_RDWR);
	if(fd==-1)
	  ERR_EXIT("open error");
	//close stdout;
	/*
	close(1);
	dup(fd);
	*/
	//dup2(fd,1);
	
	close(1);
	fcntl(fd,F_DUPFD,0);
	printf("hello\n");
	return 0;
}
