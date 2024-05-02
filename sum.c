#include <stdio.h>
#include<unistd.h>
#include<sys/wait.h>
int main(){
	int even_sum=0,odd_sum=0;
	pid_t ptd=fork();
	if(ptd<0){
		printf("fork faild\n");
		return 1;
	}
	else if(ptd==0){
		for(int i=2;i<=1000;i+=2){
		even_sum+=i;
		}
				printf("sum of even number :%d\n",even_sum);
		}
		else{
		for(int i=1;i<=1000;i+=2){
		odd_sum+=i;
		}
		printf("sum of odd number ;%d\n",odd_sum);
		
		}
	}


