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


#define MAJOR(a) (int)((unsigned short)a>>8)
#define MINOR(a) (int)((unsigned short)a&0xFF)

int filetype(struct stat* buf)
{
	int flag=0;
	printf("文件类型：");
	mode_t mode;
	mode=buf->st_mode;
	switch(mode & S_IFMT)
	{
		case S_IFSOCK:
			printf("socket\n");
			break;
		case S_IFLNK:
			printf("symbolic link\n");
			break;
		case S_IFREG:
			printf("regular file\n");
			break;
		case S_IFBLK:
			flag=1;
			printf("block device\n");
			break;
		case S_IFDIR:
			printf("directory\n");
			break;
		case S_IFCHR:
			flag=1;
			printf("character device\n");
			break;
		case S_IFIFO:
			printf("FIFO\n");
			break;
		case S_ISUID:
			printf("set-user-ID bit\n");
			break;
		default:
			printf("no type found\n");
			break;
	}
	return flag;
}

void filepermission(struct stat* buf,char* permission)
{
	switch(buf->st_mode & S_IFMT)
	{
		case S_IFSOCK:
			permission[0]='s';
			break;
		case S_IFLNK:
			permission[0]='l';
			break;
		case S_IFREG:
			permission[0]='-';
			break;
		case S_IFBLK:
			permission[0]='b';
			break;
		case S_IFDIR:
			permission[0]='d';
			break;
		case S_IFCHR:
			permission[0]='c';
			break;
		default:
			permission[0]='?';
			break;
	}
	if(buf->st_mode & S_IRUSR)
	  permission[1]='r';
	if(buf->st_mode & S_IWUSR)
	  permission[2]='w';
	if(buf->st_mode & S_IXUSR)
	  permission[3]='x';
	if(buf->st_mode & S_IRGRP)
	  permission[4]='r';
	if(buf->st_mode & S_IWGRP)
	  permission[5]='w';
	if(buf->st_mode & S_IXGRP)
	  permission[6]='x';
	if(buf->st_mode & S_IROTH)
	  permission[7]='r';
	if(buf->st_mode & S_IWOTH)
	  permission[8]='w';
	if(buf->st_mode & S_IXOTH)
	  permission[9]='x';
	permission[10]='\0';
}
int main(int argc,char **argv)
{
	if(argc!=2)
	{
		printf("Usage:%s file \n",argv[0]);
		exit(EXIT_FAILURE);
	}

	struct stat statbuf;
	printf("file name:%s \n",argv[1]);
	if(stat(argv[1],&statbuf)<0)
	  ERR_EXIT("stat");
	printf("主设备号(块号)：%d,次设备号：%d\n",MAJOR(statbuf.st_dev),MINOR(statbuf.st_dev));
	printf("i节点号：%d\n",(int)statbuf.st_ino);
	printf("硬链接数：%d\n",(int)statbuf.st_nlink);
	printf("用户id：%d\n",(int)statbuf.st_uid);
	printf("组id：%d\n",(int)statbuf.st_gid);
	printf("磁盘id：%d\n",(int)statbuf.st_rdev);
	printf("文件大小：%d\n",(int)statbuf.st_size);
	filetype(&statbuf);
	printf("文件的权限：%o  ",statbuf.st_mode & 00777);
	char permission[11]="----------";
	filepermission(&statbuf,permission);
	printf("%s\n",permission);
	return 0;
}
