#include <stdio.h>
#include "ezXPath.c"

#define MAXELEMENTS 200 /* Maximum number of results to return */

 /*
 * ezXpath examples
 */

int main(){
	char *output[MAXELEMENTS];
	int i;
	int size;

	size = ezXPathXML("https://www.sitemaps.org/sitemap.xml","/*[local-name() = 'urlset']/*[local-name() = 'url']/*[local-name() = 'loc']",output);
	if(size!=0){
		printf("Found %d elements:\n",size);
		for(i =0;i<size;i++){
			printf("%s\n",output[i]);
			free(output[i]);
		}
	}
	size = ezXPathXMLFile("sitemap.xml","/*[local-name() = 'urlset']/*[local-name() = 'url']/*[local-name() = 'loc']",output);
	if(size!=0){
		printf("Found %d elements:\n",size);
		for(i =0;i<size;i++){
			printf("%s\n",output[i]);
			free(output[i]);
		}
	}
	size = ezXPathHTML("https://www.wordsmith.org/words/today.html","/html/head/title",output);
	if(size!=0){
		printf("Found %d elements:\n",size);
		for(i =0;i<size;i++){
			printf("%s\n",output[i]);
			free(output[i]);
		}
	}
	size = ezXPathHTMLFile("example.com","/html/head/title",output);
	if(size!=0){
		printf("Found %d elements:\n",size);
		for(i =0;i<size;i++){
			printf("%s\n",output[i]);
			free(output[i]);
		}
	}
	return 1;
}

