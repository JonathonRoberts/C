#include <stdio.h>
#include "ezXPath.c"

#define MAXELEMENTS 200 /* Maximum number of results to return */

 /*
 * Using XPath to return the best odds for an event
 */

struct Market{
   float odds[MAXELEMENTS/2];
   char outcome[MAXELEMENTS/2][50];
   char *bestbookie[MAXELEMENTS/2];
   char sport;
   char *title;
   int date;
   int noodds;
};

struct Market Markets[400];

void printstruct(int i);

int main(){
	char *output[MAXELEMENTS];
	int i;
	int size;
        /*
        size = ezXPathHTML("https://www.oddschecker.com/football/champions-league/rijeka-v-tns/winner","id('t1')/tr/td[position() > 1 and not(position() > 26)]/@data-odig",output);
	if(size!=0){
		printf("Found %d elements:\n",size);
		for(i =0;i<size;i++){
                        if(i%25==0){
                           printf("\n");
                        }
			printf("%s ",output[i]);
			free(output[i]);
		}
                printf("\n");
	}
        */
        size = ezXPathHTML("https://www.oddschecker.com/football/champions-league/rijeka-v-tns/winner","id('t1')/tr/@data-best-dig|id('t1')/tr/@data-bname",output);
	if(size!=0){
		printf("Found %d elements:\n",size);
		for(i =0;i<size;i++){
                        if(i%2==0){
                           Markets[1].noodds++;
                           if(i==0){
                              Markets[1].odds[i] = atof(output[i]);
                           }
                           else{
                              Markets[1].odds[i/2] = atof(output[i]);
                           }
                        }
                        else{
                              strlcpy(Markets[1].outcome[((i+1)/2)-1] , output[i], 50);

                           }
			free(output[i]);
		}
                printstruct(1);
                printf("\n");
	}

	return 1;
}

void printstruct(int i){
   int n;
   //printf("%s\n",Markets[i].title);
   for(n = 0;n<Markets[i].noodds;n++){
      printf("%f - ",Markets[i].odds[n]);
      printf("%s - ",Markets[i].outcome[n]);
      //printf("%s",Markets[i].bestbookie[n]);
      printf("\n");
   }
   //printf("sport - %c\n",Markets[i].sport);
   //printf("date - %d\n",Markets[i].date);
}
