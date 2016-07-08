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
	fd=open("test.txt",O_CREAT | O_RDWR | O_TRUNC,0644);
	if(fd==-1)
	  ERR_EXIT("open error");
	struct flock lock;
	memset(&lock,0,sizeof(lock));
	lock.l_type=F_WRLCK;
	lock.l_whence=SEEK_SET;
	lock.l_start=0;
	lock.l_len=0;
	if(fcntl(fd,F_SETLK,&lock)<0)
	  ERR_EXIT("set lock error");
	printf("set lock success\n");
	printf("press any key to unlock\n");
	getchar();
	lock.l_type=F_UNLCK;
	if(fcntl(fd,F_SETLK,&lock)<0)
	  ERR_EXIT("unlock error");
	printf("unlock success\n");
	return 0;
}
