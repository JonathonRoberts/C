#include <stdio.h>
#include <ctype.h>
#include <unistd.h>
#include "getachar.h"

/*
 * Quick summary
 * This program checks the file permissions of the file specified as the command line argument
 * prints the file
 * then inserts into that file at the character specified by editpoint
 * to stop inserting press escape
 */

int checkfileexists(char*);

int main(int argc, char *argv[]){

	char* fname;
	FILE *fp;
	int read = 0;
	int write = 0;
	int exec = 0;
	if(argc == 2){
		fname = argv[1];
	}
	else{
		fname = "test";
	}

	if(access(fname,F_OK) !=-1){
		printf("File exists\n");
		if(access(fname,R_OK) !=-1){
			printf("File is readable\n");
			read = 1;
		}
		else{
			printf("File is not readable\n");
		}
		if(access(fname,W_OK) !=-1){
			printf("File is writeable\n");
			write = 1;
		}
		else{
			printf("File is not writeable\n");
		}
		if(access(fname,X_OK) !=-1){
			printf("File is executable\n");
			exec = 1;
		}
		else{
			printf("File is not executable\n");
		}
	}
	else{
		printf("File doesn't exist\n");
	}
	char a;


	//read file
	fp=fopen(fname,"r+");
	int n = 0, i = 0;
	int openfile[2000]; // should use malloc to grow array when needed

	int lines[2000];
	lines[0]=0;
	int lc=0;
	int characters=0;
	while( fscanf(fp, "%c,", &n) > 0 )
	{
		characters++;
		printf("%c",n);
		if(n==13){lines[++lc]=characters;}
		openfile[i++] = n;
	}

	/*
	while((a = getachar())!=27){
		switch(a){
			case 13: {fprintf(fp,"\n");printf("\n");break;}
			case 27: {break;}
			default: {fprintf(fp,"%c", a);printf("%c",a);}
		}
	}
	*/
	//write entry into temp array
	char tmp[2000];
	n = 0;
	int newcharcount=0;
	while((a = getachar())!=27){
		switch(a){
			case 13: {tmp[n++]= '\n';printf("\n");newcharcount++;break;}
			case 27: {break;}
			default: {tmp[n++] = a;printf("%c",a);newcharcount++;}
		}
	}
	//merge into edit point
	int editpoint =3;
	int fclose(FILE *a_file);
	fp=fopen(fname,"w");
	char aoeu=0;
	int counter1;
	for(counter1 = 0;counter1<=characters;counter1++){
		while(counter1>editpoint&&aoeu<newcharcount){
			printf("%c",tmp[aoeu]);
			fprintf(fp,"%c",tmp[aoeu++]);
		}
		fprintf(fp,"%c",openfile[counter1]);
		printf("%c",openfile[counter1]);
	}





	int fclose(FILE *a_file);
   return 1;
}

int checkfileexists(char* fname){;}
