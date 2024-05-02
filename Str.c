#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
FILE * file;
char filename[100];
char pattern[100];
printf("enter the filename\n");
scanf("%s",filename);
printf("enter the pattern\n");
scanf("%s",pattern);
file=fopen(filename,"r");
if(file==NULL){
	printf("error opening file\n");
	return 1;
}
char line[100];
int line_no =0;
while(fgets(line,sizeof(line),file)!=NULL){
	line_no++;
	if(strstr(line,pattern)!=NULL){
	printf("line %d :%s ",line_no,line);
	}

}
fclose(file);


}
