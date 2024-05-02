#include <stdio.h>
#include <stdlib.h>
int main()
{
   int i,j,n,m,rq[100],in,k,thm=0,s,tem[100];
   printf("Enter the number of requests: ");
   scanf("%d", &n);
   printf("Enter the requests sequence: ");
   for(int i=0;i<n;i++)
   {
    scanf("%d",&rq[i]);
   }
   printf("Enter the initial Head position: ");
   scanf("%d",&in);
   k=in;
   printf("Enter the total disk tracks: ");
   scanf("%d",&m);
   int dts=0;
   int dte=m-1;
   
   for(i=0;i<n;i++)
   {
      thm+=abs(rq[i]-in);
      in=rq[i];
   }
    
   printf("\nTotal Head Movements(FIFO): %d",thm);
   
   for(i=0;i<n;i++) 
    {                    
        for(j=0;j<n-i-1;j++)
        {
             if(rq[j]>rq[j+1])
             {
                int temp=rq[j];
                rq[j]=rq[j+1];
                rq[j+1]=temp;
             }
        } 
    }
    i=0;
    thm=(dte-k)+(dte-rq[i]);
    printf("\nTotal Head Movements(SCAN): %d",thm);
    
    
    for(j=1;j<n;j++){
        if(rq[j]<k){
            s=rq[j];
        }
    }
        
    
    

    thm=(dte-in)+dte+s;
    printf("\nTotal Head Movements(C-SCAN): %d",thm);
}
