#include<stdio.h>
struct process{
int id,at,bt;
}arr[10];
void FCFS(int n){
int currenttime=0;
printf("Gant chart for FCFS sheduling\n");
printf("[\t");
for (int i=0;i<n;i++){
printf("p%d \t ",arr[i].id);
}
printf("]\n");
printf("[");
for(int i=0;i<n;i++){
printf("%d \t",currenttime);
currenttime+=arr[i].bt;
}
printf("%d \t",currenttime);
printf("]");
printf("\n");

}

void SJF(int n){
int current_time=0;
printf("Gant chart for SJF sheduling\n");
printf("[\t");
for(int i=0;i<n;i++){
	for(int j=0;j<n-i-1;j++){
		if(arr[j].bt>arr[j+1].bt){
		struct process temp=arr[j];
		arr[j]=arr[j+1];
		arr[j+1]=temp;
		}
	}
}
for(int i=0;i<n;i++){
printf("p%d\t",arr[i].id);
}
printf("]\n");
printf("[");
for(int i=0;i<n;i++){
printf("%d\t",current_time);
current_time+=arr[i].bt;
}
printf("%d\t",current_time);
printf("]\n");
}
int main(){
printf("enter the number of process\n");
int n;
scanf("%d",&n);
for(int i=0;i<n;i++){
printf("enter the id,arrival time and burst time of process%d\n",i+1);
scanf("%d%d%d",&arr[i].id,&arr[i].at,&arr[i].bt);


}
FCFS(n);
SJF(n);

}
