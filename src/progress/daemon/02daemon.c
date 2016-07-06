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

int main(void)
{
	//这里直接调用daemon函数就可以创建一个守护进程了；
	daemon(0,0);
	printf("hello i am daemon\n");
	while(1);
	return 0;
}
