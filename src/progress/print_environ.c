#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>

#define ERR_EXIT(m) \
	do { \
		perror(m); \
		exit(EXIT_FAILURE); \
	}while(0)

extern char** environ;
int main(void)
{
	int i;
	for(i=0;environ[i]!=NULL;++i)
	{
		printf("%s\n",environ[i]);
	}
	return 0;
}
