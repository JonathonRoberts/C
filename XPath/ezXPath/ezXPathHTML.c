#include <stdio.h>
#include <libxml/xpath.h>
#include <libxml/HTMLparser.h>/*htmlReadFile*/
#include "ezcurl.c"

/* An example XPath program for returning elements from an XML file */

xmlNodeSetPtr getnodeset(xmlDocPtr doc,xmlChar *xpath);

int extern ezXPathHTML(char *website,char *expr,char *output[]){
	xmlInitParser();
	//char *expr = "/html/head/title";
	int i;
	int size;
	/*
	 *
	 * xpath1 syntax for ignoring namespace
	 * char *expr = "/*[local-name() = 'sitemapindex']/*[local-name() = 'sitemap']/*[local-name() = 'loc']";
	 * xpath2 syntax for ignoring namespace
	 * char *expr = "/*:sitemapindex/*:sitemap/*:loc";
	 *
	 * char *docname = "Sitemap.xml";
	 *
	 * For downloading and parsing xml websites
	 * xmlDocPtr doc = xmlParseDoc(ezcurl("https://www.sitemaps.org/sitemap.xml");
	 *
	 * For parsing xml files
	 * xmlDocPtr doc = xmlParseFile(docname);
	 *
	 * For parsing html files
	 * xmlDocPtr doc = htmlReadFile(docname, NULL, HTML_PARSE_NOBLANKS | HTML_PARSE_NOERROR | HTML_PARSE_NOWARNING | HTML_PARSE_NONET);
	 *
	 * For downloading and parsing html sites */
	//xmlDocPtr doc = htmlParseDoc(ezcurl("example.com"),NULL);
	xmlDocPtr doc = htmlParseDoc(ezcurl(website),NULL);
	xmlChar *xpath = (xmlChar*) expr;
	xmlNodeSetPtr nodeset;
	xmlXPathObjectPtr result;
	xmlChar *element;
	result = getnodeset(doc,xpath);

	if(result){
		nodeset = result->nodesetval;
		size = nodeset->nodeNr;
		for(i=0;i<size;i++){
			element = xmlNodeListGetString(doc,nodeset->nodeTab[i]->xmlChildrenNode,1);
			sscanf(element, "%[^0]",output[i]);/* converts (xmlchar *)element into a regular c string */
			xmlFree(element);
		}
		xmlXPathFreeObject(result);
	}

	xmlFreeDoc(doc);
	xmlCleanupParser();
	return size;
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
