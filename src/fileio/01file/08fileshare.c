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
	char buf1[1024]={0};
	char buf2[1024]={0};
	fd1=open("test.txt",O_RDONLY);
	if(fd1==-1)
	  ERR_EXIT("open error");
	int ret=read(fd1,buf1,5);
	if(ret==-1)
	  ERR_EXIT("read error");
	printf("buf1=%s\n",buf1);
	fd2=open("test.txt",O_RDWR);
	if(fd2==-1)
	  ERR_EXIT("open error");
	ret=read(fd2,buf2,5);
	if(ret==-1)
	  ERR_EXIT("read error");
	printf("buf2=%s\n",buf2);
	write(fd2,"AAAAA",5);
	memset(buf1,0,sizeof(buf1));
	ret=read(fd1,buf1,5);
	if(ret==-1)
	  ERR_EXIT("read error");
	printf("buf1=%s\n",buf1);
	close(fd1);
	close(fd2);
	return 0;
}
