#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
FILE * file;
char filename[100];
char ch;
int lines=0,word=0,charcount=-2;
printf("enter the filename\n");
scanf("%s",filename);

file=fopen(filename,"r");
if(file==NULL){
	printf("error opening file\n");
	return 1;
}

while((ch=fgetc(file))!=EOF){
	charcount++;
	if( ch=='\t' || ch=='\n' || ch=='\r')
	word++;
	if(ch=='\n')
	lines++;
}
/*
if(charcount>0){
word++;
}*/
fclose(file);
printf("charcount:%d\n",charcount);
printf("words:%d\n",word);
printf("lines:%d\n",lines);

}
