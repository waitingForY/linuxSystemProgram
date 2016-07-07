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


/*
 *add read lock using fcntl function
 *
 */
int set_lock(int fd)
{
	struct flock lck;
	lck.l_type=F_RDLCK;
	lck.l_whence=SEEK_SET;
	lck.l_start=0;
	lck.l_len=0;
	int ret=fcntl(fd,F_SETLK,&lck);
	return ret;
}


/*
 *clear lock using file discripation
 */


int clr_lock(int fd)
{
	struct flock lck;
	lck.l_type=F_UNLCK;
	int ret=fcntl(fd,F_SETLK,&lck);
	return ret;
}

int main(void)
{
	int fd;
	fd=open("test.txt",O_RDWR);
	if(fd==-1)
	  ERR_EXIT("open error");
	int ret;
	ret=set_lock(fd);
	if(ret==-1)
	  ERR_EXIT("set_lock error");
	printf("set_lock success\n");
	printf("press any key to unlock\n");
	getchar();
	ret=clr_lock(fd);
	if(ret==-1)
	  ERR_EXIT("clear lock error");
	printf("clear lock success\n");
	return 0;
}
