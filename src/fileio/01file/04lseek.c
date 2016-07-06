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
	fd=open("test.txt",O_RDONLY);
	if(fd==-1)
	  ERR_EXIT("open error");
	char readbuf[1024]={0};
	int ret=read(fd,readbuf,5);
	if(ret==-1)
	  ERR_EXIT("read error");
	printf("readbuf=%s\n",readbuf);
	ret=lseek(fd,0,SEEK_CUR);
	if(ret==-1)
	  ERR_EXIT("lseek error");
	printf("current offset=%d\n",ret);
	return 0;
}
