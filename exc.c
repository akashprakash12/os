#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#define N 100
int main(){
char input[N];
scanf("%s",input);
while(strcmp(input,"stop")!=0){
	int a=fork();
	if(a==-1){
		printf("fork impossiable");
		exit(1);
	}
	if(a==0){
		printf("\n");
		if(execlp(input," ",NULL)){
		printf("error execut");
		exit(0);
		
		}
		exit(0);
	}
	wait(0);
	scanf("%s",input);
	
	
}


}
