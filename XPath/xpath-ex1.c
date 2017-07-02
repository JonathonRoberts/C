#include <stdio.h>
#include <libxml/xpath.h>

xmlNodeSetPtr getnodeset(xmlDocPtr doc,xmlChar *xpath);

int main(){
	xmlInitParser();
	char *docname = "sitemap.xml";
	//char *expr = "/*:sitemapindex/*:sitemap/*:loc";//xpath2 syntax
	char *expr = "/*[local-name() = 'sitemapindex']/*[local-name() = 'sitemap']/*[local-name() = 'loc']";
	int i;
	int size;

	xmlDocPtr doc = xmlParseFile(docname);
	xmlChar *xpath = (xmlChar*) expr;
	xmlNodeSetPtr nodeset;
	xmlXPathObjectPtr result;
	xmlChar *element;
	result = getnodeset(doc,xpath);

	if(result){
		nodeset = result->nodesetval;
		printf("Found %i elements:\n",size = nodeset->nodeNr);
		for(i=0;i<size;i++){
			element = xmlNodeListGetString(doc,nodeset->nodeTab[i]->xmlChildrenNode,1);
			printf("%s\n",element);
			xmlFree(element);
		}
		xmlXPathFreeObject(result);
	}

	xmlFreeDoc(doc);
	xmlCleanupParser();
	return 1;
}

xmlNodeSetPtr getnodeset(xmlDocPtr doc,xmlChar *xpath){
	xmlXPathObjectPtr result;
	xmlXPathContextPtr context;
	context = xmlXPathNewContext(doc);
	if(context==NULL){
		printf("Error in xmlXpathNewContext\n");
		return NULL;
	}
	result = xmlXPathEvalExpression(xpath,context);
	xmlXPathFreeContext(context);
	if(result==NULL){
		printf("Error in xmlXpathEvalExpression\n");
		return NULL;
	}
	if(xmlXPathNodeSetIsEmpty(result->nodesetval)){
		xmlXPathFreeObject(result);
		printf("No Results\n");
		return NULL;
	}
	return result;
}
