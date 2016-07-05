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

int main(void)
{
	char* env[]={"AA=11","BB=22",NULL};
	int ret=execle("./print_environ","print_environ",NULL,env);
	if(ret==-1)
	  ERR_EXIT("execle error");
	return 0;
}
