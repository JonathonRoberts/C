#include <stdio.h>
#include "ezXPath.c"

int main(){
	char **output;
	**output = malloc(0);
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
	printf("%s",output);
	size = ezXPathHTMLFile("example.com","/html/head/title",output);
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
	output = malloc(40000);

	size = ezXPathXML("https://www.sitemaps.org/sitemap.xml","/*[local-name() = 'urlset']/*[local-name() = 'url']/*[local-name() = 'loc']",output);
	if(size!=0){
		printf("Found %d elements:\n",size);
		for(i =0;i<size;i++){
			printf("%s\n",output[i]);
			free(output[i]);
		}

	}
	size = ezXPathXML("https://www.sitemaps.org/sitemap.xml","/*[local-name() = 'urlset']/*[local-name() = 'url']/*[local-name() = 'loc']",output);
	if(size!=0){
		printf("Found %d elements:\n",size);
		for(i =0;i<size;i++){
			printf("%s\n",output[i]);
			free(output[i]);
		}
	}


	return 1;
}
