#include<stdio.h>
#include <stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#define num_file 3
int files[num_file];
void cleanup(){
for(int i=0;i<num_file;i++){
	if(files[i]!=-1){
	close(files[i]);
	}
	
}
}
int main(){
	files[0]=open("file1.txt",O_RDONLY|O_CREAT);
	files[1]=open("file2.txt",O_WRONLY |O_CREAT | O_TRUNC ,S_IRUSR | S_IWUSR);
	files[2]=open("file3.txt",O_WRONLY | O_CREAT|O_TRUNC,S_IRUSR|S_IWUSR );
	for (int i=0;i<=num_file;i++){
		if(files[i]==-1){
		printf("error opening file");
		cleanup();
	
		exit(1);
		}
	}
	printf("file cleanup successfully");
atexit(cleanup);
}

