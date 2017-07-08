#include <stdio.h>
#include "ezXPath.c"

int main(){
	xmlInitParser();

	char *output[0];
	int i;
	int size = 0;
	size = ezXPathHTML("example.com","/html/head/title",output);
	if(size!=0){
		printf("Found %d elements:\n",size);
		for(i =0;i<size;i++){
			printf("%s\n",output[i]);
			free(output[i]);
		}
	}
	size = ezXPathHTML("example.com","/html/head/title",output);
	if(size!=0){
		printf("Found %d elements:\n",size);
		for(i =0;i<size;i++){
			printf("%s\n",output[i]);
			free(output[i]);
		}
	}
	size = ezXPathXML("https://www.sitemaps.org/sitemap.xml","/*[local-name() = 'urlset']/*[local-name() = 'url']/*[local-name() = 'loc']",output);
	//*output = realloc(*output,size);
	if(size!=0){
		printf("Found %d elements:\n",size);
		for(i =0;i<size;i++){
			printf("%s\n",output[i]);
			free(output[i]);
		}
	}


	xmlCleanupParser();
	return 1;
}
