#include <stdio.h>
#include "ezXPathHTML.c"

int main(){
	unsigned char *output[200];
	int i;
	int size = ezXPathHTML("example.com","/html/head/title",output);
	printf("%s\n",output[0]);

	return 1;
}
