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
	printf("open file success\n");
	return 0;
}
