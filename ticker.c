#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>

void rotate(char string[]);
void addquote(char string[], char tick[]);

#define LENGTH 300

int n = 0;
main(){
   while(1){
   char string[LENGTH]= "";

   addquote(string, "jnug");
   addquote(string, "nugt");
   addquote(string, "rgld");
   addquote(string, "GOLD");

   int i;
   for(i = 0;i<30;i++)
      rotate(string);
   }
}

void rotate(char string[]){
   int length = strlen(string);
   int i;
   for(i=0;i<length;i++){
      printf("%c",string[n++]);
      if(n>length)
         n = 0;
      usleep(1);
   }
   system("clear");
   printf("\n");
}

void addquote(char string[], char tick[]){

   //Create API Link
   char apilink[LENGTH] = "/usr/local/bin/curl -s 'http://download.finance.yahoo.com/d/quotes.csv?s=";
   strlcat( apilink, tick, LENGTH);
   strlcat( apilink, "&f=l1c'", LENGTH);

   //get quote
   char price[100];
   FILE *fp;
   fp = popen(apilink, "r");
   fscanf(fp, "%s",&price);
   pclose(fp);

   //append ticker and quote to string
    strlcat( string, tick, LENGTH);
    strlcat( string, ": ", LENGTH);
    strlcat( string, price, LENGTH);
    strlcat( string, "     ", LENGTH);

}
