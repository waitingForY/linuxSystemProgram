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
	fd=open("hole.txt",O_WRONLY | O_CREAT | O_TRUNC | O_SYNC, 0644);
	if(fd==-1)
	  ERR_EXIT("open error");
	write(fd,"ABCDE",5);
	int ret;
	ret=lseek(fd,32,SEEK_CUR);
	if(ret==-1)
	  ERR_EXIT("lseek error");
	write(fd,"hello",5);
	close(fd);
	return 0;
}
