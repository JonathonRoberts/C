#include <stdio.h>
#include <libxml/xpath.h>
#include <libxml/HTMLparser.h>//htmlReadFile


/* An example XPath program for returning elements from an XML file */

xmlNodeSetPtr getnodeset(xmlDocPtr doc,xmlChar *xpath);

int main(){
	xmlInitParser();
	//char *docname = "riseup.html";
	char *docname = "Sitemap.xml";
	//char *expr = "/*:sitemapindex/*:sitemap/*:loc";//xpath2 syntax
	char *expr = "/*[local-name() = 'sitemapindex']/*[local-name() = 'sitemap']/*[local-name() = 'loc']";
	//char *expr = "/html/head/title";
	int i;
	int size;

	/*
	For reading html files
	xmlDocPtr doc = htmlReadFile(docname, NULL, HTML_PARSE_NOBLANKS | HTML_PARSE_NOERROR | HTML_PARSE_NOWARNING | HTML_PARSE_NONET);

	figure out how to get curl into the program and then find out what goes there

	xmlDocPtr doc = htmlParseDoc(whatgoeshere, NULL, HTML_PARSE_NOBLANKS | HTML_PARSE_NOERROR | HTML_PARSE_NOWARNING | HTML_PARSE_NONET);

	xmlDocPtr doc = xmlParseDoc(whatgoeshere);
	*/
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
