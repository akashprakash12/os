#include<stdio.h>
#define max_resourse 2
#define max_process 2
int need[max_process][max_process];
int available[max_resourse];
int allocation[max_process][max_resourse];
int need_sum[max_resourse];
int work [max_resourse],finish [max_process];
int is_safe(){
int i,j,k,flag=1;
	for(i=0;i<max_process;i++){
		if(finish[i]=0){
			for (int k=0;k<max_resourse;k++){
			if(need[i][k]>available[k]){
			flag=0;
			break;
			}
			} 
		if(flag==1){
		work[k]+=allocation[i][k];
		finish[i]=1;
		
		}
	}
}
for(i=0;i<max_process;i++){
if(finish[i]==0){
return 0;
}
return 1;
}
}

int main(){
int i,j;
printf("enter allocation matrix\n");
	for(i=0;i<max_process;i++){
		for(j=0;j<max_resourse;j++){
		scanf("%d",&allocation[i][j]);
		}
	}
printf("enter need matrix\n");
	for(i=0;i<max_process;i++){
		for(j=0;j<max_resourse;j++){
		scanf("%d",&need[i][j]);
		}
	}
printf("enter the available vector\n");
	for(i=0;i<max_resourse;i++){
		scanf("%d",&available[i]);
	}
	for(i=0;i<max_process;i++){
		for(j=0;j<max_resourse;j++){
		need_sum[j]+=need[i][j];
		}
	}
	for(i=0;i<max_resourse;i++){
		if(available[i]<need_sum[i]){
			printf("system is in unsafe\n");
			return 0;
		}
	}
	for (i=0;i<max_process;i++){
	finish[i]=0;
	for(i=0;i<max_process;i++){
	work[i]=available[i];
	}
	if(is_safe()==1){
	printf("system is safe state\n");
	}else{
	printf("system is in unsafe state\n");
	}
	}
	return 0;
}

