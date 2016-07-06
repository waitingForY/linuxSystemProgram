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
	int fd1,fd2;
	char buf[1024]={0};
	fd1=open("test.txt",O_RDONLY);
	if(fd1==-1)
	  ERR_EXIT("open error");
	int ret=read(fd1,buf,5);
	if(ret==-1)
	  ERR_EXIT("read error");
	printf("buf=%s\n",buf);
	fd2=open("test.txt",O_RDONLY);
	if(fd2==-1)
	  ERR_EXIT("open error");
	ret=read(fd2,buf,5);
	if(ret==-1)
	  ERR_EXIT("read error");
	printf("buf=%s\n",buf);
	return 0;
}
