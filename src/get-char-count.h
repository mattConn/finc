#include "document-attributes.h"

int get_char_count(char *filename)
{
	int char_count = 0;
	doc.char_count = 0;
	
    //open file for scanning
    doc.infile = fopen(filename, "r");

    //get char count of document
    while(doc.infile_char != EOF)
	{
		doc.infile_char = fgetc(doc.infile);
        doc.char_count++;
	};

	char_count = doc.char_count;

    //reset: back to top of infile, reset document char count 
    rewind(doc.infile);
    doc.char_count = 0;

    return char_count;
}

