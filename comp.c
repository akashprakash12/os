#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
FILE * FILE1,*FILE2;
char fileA[100];
char fileB[100];
printf("enter the file name\n");
scanf("%s%s",fileA,fileB);
FILE1=fopen(fileA,"r");
FILE2=fopen(fileB,"r");
if(FILE1==NULL || FILE2==NULL){
	printf("enter opening file\n");
	return 0;
}
int line_num=0;
char line1[100],line2[100];
while(fgets(line1,sizeof(line1),FILE1)!=NULL && fgets(line2,sizeof(line2),FILE2)!=NULL){
if(strcmp(line1,line2)!=0){
printf("Difference at line %d\n",line_num);
printf("file1 %s\n ",line1);
printf("file2 %s\\n",line2);
}
}

while (fgets(line1,sizeof(line1),FILE1)!=NULL){
printf("enter line in files1:\n");
printf("file1 %s",line1);

}
while (fgets(line1,sizeof(line1),FILE2)!=NULL){
printf("enter line in files2:\n");
printf("file2 %s",line2);

}
}
