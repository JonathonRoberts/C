#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

float setreturn(int noodds, float odds[]);

int main(int argc, char *argv[]){
	int i;
	int noodds = argc-1;
	float odds[noodds];
	for(i=1;i<argc;i++){
		odds[i-1] = atof(argv[i]);
	}
	float returnodds =setreturn(noodds, odds);
	float totalstake = 100;
	int firstrunflag = 0;
	char str[15];
	int a;
	float returncash;
	while(1){
		if(firstrunflag == 0){
			//system("clear");
			firstrunflag++;
		}
		else{
			fgets(str,15,stdin);
		}
		//if only one character is entered a = character entered
		if(str[2]==0){
			a = str[0];
		}

		switch(a){
			//case: 'c' {changeodds();break;}
			case 'q': return 0;
			default: {totalstake =atof(str);
				  returncash = totalstake*returnodds;
				  a = 0;
				 }
			}
		//Output
		printf("Total stake: %.2f\n",totalstake);
		printf("Total return:  %.2f\n",returncash);
		for(i = 0;i<noodds;i++){
			printf("%.2f\t%.2f\n",odds[i],(returncash/odds[i]));
		}
		printf("Input total stake: ");
		}


	}

float setreturn(int noods, float odds[]){
	int i;
	float returnodds = 0;
	for(i = 0;i<noods;i++){
		returnodds += (1/odds[i]);
	}
	return (1/returnodds);
}
