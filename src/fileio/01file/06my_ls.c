#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <error.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>


#define ERR_EXIT(m) \
	do{ \
		perror(m); \
		exit(EXIT_FAILURE); \
	}while(0)

int main(void)
{
	DIR *dir=opendir(".");
	if(dir==NULL)
	  ERR_EXIT("opendir error");
	struct dirent *dent;
	while((dent=readdir(dir))!=NULL)
	{
		if(strncmp(dent->d_name,".",1)==0)
		  continue;
		printf("%s\n",dent->d_name);
	}
	closedir(dir);
	return 0;
}
