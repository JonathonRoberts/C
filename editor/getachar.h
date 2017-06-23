#include <stdio.h>

extern char getachar();
char getachar(){
	char ch;
	system("/bin/stty raw");
	ch = getchar();
	system("/bin/stty cooked");
	return ch;
}

