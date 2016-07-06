#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


#define ERR_EXIT(m) \
	do { \
		perror(m); \
		exit(EXIT_FAILURE); \
	}while(0)

int mydaemon(int nochdir,int noclose)
{
	pid_t pid;
	pid=fork();
	if(pid==-1)
	  //ERR_EXIT("fork error");
	  return -1;
	if(pid>0)
	  exit(EXIT_SUCCESS);
	else if(pid==0)
	{
		int ret=setsid();
		if(ret==-1)
		  //ERR_EXIT("setsid error");
		  return -1;
		if(nochdir==0)
		  chdir("/");
		if(noclose==0)
		{
			int i;
			for(i=0;i<3;++i)
			  close(i);
			dup(0);
			dup(0);
		}
	}
	return 0;
}


int main(void)
{
	//这里直接调用daemon函数就可以创建一个守护进程了；
	//daemon(0,0);
	//如果是传的1,1就表示不更改工作目录也不重定向三个标准io；
	//daemon(1,1);
	mydaemon(1,1);
	printf("hello i am daemon\n");
	while(1);
	return 0;
}
