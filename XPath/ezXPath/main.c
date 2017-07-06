#include <stdio.h>
#include "ezXPathHTML.c"
/*
static void func(char *p[])
{
    p[0] = "Hello";
    p[1] = "World";
}
int main(int argc, char *argv[])
{
    char *strings[2];
    func(strings);
    printf("%s %s\n", strings[0], strings[1]);
    return 0;
}
*/
int main(){
	unsigned char *output[200];
	int i;
	int size = ezXPathHTML("example.com","/html/head/title",output);
	printf("\n%d\n",size);
	printf("%d\n",output[0][8]);

	return 1;
}
