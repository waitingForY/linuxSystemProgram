#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <error.h>
#include <string.h>

#define ERR_EXIT(m) \
	do{ \
		perror(m); \
		exit(EXIT_FAILURE); \
	}while(0)

int main(void)
{
	printf("fileno(stdin)=%d\nfileno(stdout)=%d\nfileno(stderr)=%d\n",fileno(stdin),fileno(stdout),fileno(stderr));
	return 0;
}
