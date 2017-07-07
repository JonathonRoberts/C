#include <stdio.h>
#include "ezXPathHTML.c"

int main(){
	char **output;
	int i;
	int size = ezXPathHTML("example.com","/html/head/title",output);
	printf("Found %d elements:\n",size);
	if(size!=0)
		for(i =0;i<size;i++){
			printf("%s\n",output[i]);
		}
	return 1;
}
