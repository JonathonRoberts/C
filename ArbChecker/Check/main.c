#include <stdio.h>
#include "ezXPath.c"

#define MAXELEMENTS 200 /* Maximum number of results to return */

 /*
 * Using XPath to return the best odds for an event
 */

int main(){
	char *output[MAXELEMENTS];
	int i;
	int size;
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
        size = ezXPathHTML("https://www.oddschecker.com/football/champions-league/rijeka-v-tns/winner","id('t1')/tr/@data-best-dig|id('t1')/tr/@data-bname",output);
	if(size!=0){
		printf("Found %d elements:\n",size);
		for(i =0;i<size;i++){
                        if(i%2==0){
                           printf("\n");
                        }
			printf("%s ",output[i]);
			free(output[i]);
		}
                printf("\n");
	}

	return 1;
}

