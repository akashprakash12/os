#include<stdio.h>
struct process{
   int id;
   int wt;
   int at;
   int prio;
   int tat;
   int bt;
   int ct;
   }arr[100];
   
 void read(int n){
     for(int i=0;i<n;i++){
        printf("enter the id,arrival time,priority,and burst time of process %d\n",i+1);
       scanf("%d%d%d%d",&arr[i].id,&arr[i].at,&arr[i].prio,&arr[i].bt);
       }
      }
      
  void sort(int n){
    struct process p;
    for(int i=0;i<n;i++){
       for(int j=0;j<n-i-1;j++){
         if(arr[j].prio>arr[j+1].prio){
           p=arr[j];
           arr[j]=arr[j+1];
           arr[j+1]=p;
         }
        }
      }
    }
    
void priority(int n){
   int total_bt=0;
   int total_wt=0,total_tat=0,total_ct=0;
   arr[0].wt=0;
   arr[0].tat=arr[0].bt;
   arr[0].ct=arr[0].bt+arr[0].at;
   total_tat+=arr[0].tat;
   total_bt+=arr[0].bt;
   total_ct+=arr[0].ct;
   for(int i=1;i<n;i++){
       arr[i].wt=total_bt-arr[i].at;
       if(arr[i].wt<=0)
           arr[i].wt=0;
       arr[i].tat=arr[i].bt+arr[i].wt;
       arr[i].ct=arr[i].bt+arr[i].wt+arr[i].at;
       total_ct+=arr[i].ct;
       total_bt+=arr[i].bt;
       total_tat+=arr[i].tat;
       total_wt+=arr[i].wt;
    }
     float avg_ct=(float)total_ct/(float)n;
     float avg_wt=(float)total_wt/(float)n;
     float avg_tat=(float)total_tat/(float)n;
     printf("average completion time=%f\n",avg_ct);
     printf("average waiting time=%f\n",avg_wt);
     printf("average turn around time=%f\n",avg_tat);
 }
     
  void main(){ 
      int n;
      printf("enter the number of process\n");
      scanf("%d",&n);
      read(n);
      sort(n);
      priority(n);
       printf("id\tat\tprio\tbt\ttat\tct\twt\n");
          for(int i=0;i<n;i++){
              printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\t",arr[i].id,arr[i].at,arr[i].prio,arr[i].bt,arr[i].tat,arr[i].ct,arr[i].wt);
              printf("\n");
         }
   }
     
