#include <stdio.h>
#include <libxml/xpath.h>

xmlNodeSetPtr getnodeset(xmlDocPtr doc,xmlChar *xpath);

int main(){
	xmlInitParser();
	char *docname = "sample.xml";
	char *expr = "/books/book[@id=\"8901\"]/edition[text()]";
	int i;
	int size;

	xmlDocPtr doc = xmlParseFile(docname);
	xmlChar *xpath = (xmlChar*) expr;
	xmlNodeSetPtr nodeset;
	xmlXPathObjectPtr result;
	xmlChar *element;

	result =getnodeset(doc,xpath);

	if(result){
		nodeset = result->nodesetval;
		size = nodeset->nodeNr;
		for(i=0;i<size;i++){
			element = xmlNodeListGetString(doc,nodeset->nodeTab[i]->xmlChildrenNode,1);
			printf("Element: %s\n",element);
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
