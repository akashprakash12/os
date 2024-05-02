#include<stdio.h>
struct process{
int id;
int waiting_time;
int arrival_time;
int turnaround_time;
int burst_time;
int completion_time;

}arr[100];

void read(int n){

	for(int i=0;i<n;i++){
	printf("enter the arrivaltime and burst time%d\n",i+1);
		scanf("%d%d%d",&arr[i].id,&arr[i].arrival_time,&arr[i].burst_time);
	}

}
void sort(int n){
	struct process p;
	for(int i=0;i<n;i++){
		for(int j=0;j<n-1-1;j++){
			if(arr[j].arrival_time>arr[j+1].arrival_time){
				p=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=arr[j];
			}
		}
	}

}

void FCFS(int n){
int total_burst_time=0;
int total_waiting_time=0,total_turnaround_time=0;
arr[0].waiting_time=0;
arr[0].turnaround_time=arr[0].burst_time;
arr[0].completion_time=arr[0].burst_time+arr[0].arrival_time;
total_turnaround_time+=arr[0].turnaround_time;
total_burst_time+=arr[0].burst_time;
for(int i=0;i<n;i++){
arr[i].waiting_time=total_burst_time-arr[i].arrival_time;
if(arr[i].waiting_time<0){
arr[i].waiting_time=0;
}
arr[i].turnaround_time=arr[i].burst_time+arr[i].waiting_time;
arr[i].completion_time=arr[i].burst_time+arr[i].waiting_time+arr[i].arrival_time;
total_burst_time+=arr[i].burst_time;
total_turnaround_time+=arr[i].turnaround_time;
total_waiting_time+=arr[i].waiting_time;

}
float avg_wt=total_waiting_time/n;
float avg_tot=total_turnaround_time/n;
printf("average waiting time:%f\n",avg_wt);
printf("average turnaround  time:%f\n",avg_tot);


}
void main(){
printf("enter the number of process\n");
int n;
scanf("%d",&n);
read(n);
FCFS(n);
printf("id\tat\tbt\ttat\tct\twt\n");
for(int i=0;i<n;i++){

printf("%d\t%d\t%d\t%d\t%d\t%d\t",arr[i].id,arr[i].arrival_time,arr[i].burst_time,arr[i].turnaround_time,arr[i].completion_time,arr[i].waiting_time);
printf("\n");
}

}


