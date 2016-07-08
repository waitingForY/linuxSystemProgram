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
 *set flag using fcntl function
 *
 */
void set_flag(int fd,int flag)
{
	int val=fcntl(fd,F_GETFL,0);
	if(val==-1)
	  ERR_EXIT("get flag error");
	val |=flag;
	if(fcntl(fd,F_SETFL,val)==-1)
	  ERR_EXIT("set flag error");
	printf("set flag success\n");
}
/*
 *clear flag using file discripation
 */
void clr_flag(int fd,int flag)
{
	int val=fcntl(fd,F_GETFL,0);
	if(val == -1)
	  ERR_EXIT("get flag error");
	val &=~flag;
	if(fcntl(fd,F_SETFL,val)==-1)
	  ERR_EXIT("set flag perror");
	printf("clear flag success\n");
}
int main(void)
{
	char buf[1024]={0};
	set_flag(0,O_NONBLOCK);
	clr_flag(0,O_NONBLOCK);
	int ret=read(0,buf,1024);
	if(ret==-1)
	  ERR_EXIT("read error");
	printf("buf=%s\n",buf);
	return 0;
}
