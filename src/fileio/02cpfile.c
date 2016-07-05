#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#define ERR_EXIT(m) \
	do{ \
		perror(m); \
		exit(EXIT_FAILURE); \
	}while(0)

int main(int argc,char **argv)
{
	int src_fp,des_fp;
	/*
	if((fp=open("test.txt",O_RDONLY))<0)
	  ERR_EXIT("open file:");
	*/
	if(argc<3)
	{
		printf("Usage: %s src des \n",argv[0]);
		exit(EXIT_FAILURE);
	}
	if((src_fp=open(argv[1],O_RDONLY))<0)
	  ERR_EXIT("open file:");
	//printf("open success\n");
	char buf[1024]={0};
	if((des_fp=open(argv[2],O_WRONLY|O_CREAT|O_EXCL,0664))<0)
	  ERR_EXIT("open file:");
	int ret;
	while((ret=read(src_fp,buf,sizeof(buf))))
	{
		write(des_fp,buf,ret);
	}
	return 0;
}
