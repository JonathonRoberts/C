#include <stdio.h>
#include <string.h>
#include <stdlib.h>

float setreturn(int noodds, float odds[]);
void changeodds(int *noodds, float *op);

int main(int argc, char *argv[]){
	int i;
	int noodds = argc-1;//number of odds
	if(noodds<2){
		printf("Two or more odds required\n");
		return 0;
	}
	float odds[20];
	float *op;//odds pointer required for changeodds()
	op = odds;
	for(i=1;i<argc;i++){
		odds[i-1] = atof(argv[i]);
	}
	float returnodds = setreturn(noodds, odds);
	float totalstake = 100;
	int firstrunflag = 0;
	char str[15];
	int a;
	float returncash = totalstake * returnodds;
	while(1){
		if(firstrunflag == 0){
			firstrunflag++;
		}
		else{
			fgets(str,15,stdin);
			//if only one character is entered a = character entered
			if(str[2]==0){
				a = str[0];
			}
			switch(a){
				case 'c': {changeodds(&noodds,op);
					  returnodds = setreturn(noodds,odds);
					  returncash = totalstake*returnodds;break;}
				case 'q': return 0;
				default: {totalstake =atof(str);
						 returncash = totalstake*returnodds;}
			}
		}
		a = 0;
		//Output
		system("clear");
		printf("c - change odds : q - quit\n");
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

void changeodds(int *noodds, float *op){
	char str[60];
	do{
		printf("Enter odds seperated by a space: ");
		*noodds = 0;
		char *p = str;
		char tmpword[10];
		if (fgets(str, sizeof str, stdin) != NULL) {
			while (sscanf(p, "%s",tmpword ) != -1) {
				op[(*noodds)++] = atof(tmpword);
				p+= strlen(tmpword)+1;

			  }
		}
	}while((*noodds)<2);
}
