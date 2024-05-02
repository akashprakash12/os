#include<stdio.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<unistd.h>
#include<time.h>

int main(){
	char file_name[100];
	struct stat filestat;
	printf("enter the file name");
	scanf("%s",file_name);
	if(stat(file_name,&filestat)<0){
		printf("error");
		exit(1);
	}
	printf("\n filesize:%ld bytes \n",filestat.st_size);
	printf("permission");
	if(filestat.st_mode&R_OK)
		printf("read");
	if(filestat.st_mode&W_OK)
		printf("write");
	if(filestat.st_mode&X_OK)
		printf("execute");
		printf("\n");
	printf("creation time:%s",ctime(&filestat.st_ctime));
	printf("modification time:%s",ctime(&filestat.st_mtime));
	printf("last access time:%s",ctime(&filestat.st_atime));
}
