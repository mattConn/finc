#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "file-attributes.h"
#include "util/reset-file-attr.h"
#include "get-char-count.h"
#include "copy-file.h"

int main(int argc, char *argv[])
{
	char output[ get_char_count(argv[1]) ];
	copy_file(argv[1], output);	

	char direc_str[] = {"##INCLUDE"};

	//check if at least one directive exists
	char direc_match[sizeof(direc_str)/sizeof(direc_str[0])];

	for(int i = 0; i < sizeof(output)/sizeof(output[0]); i++)
	{
		// check for first two characters of directive
		if(output[i] == direc_str[0] && output[i+1] == direc_str[1])
		{
			// make sure a complete directive is actually present
			for(int j = 0; j < sizeof(direc_str)/sizeof(direc_str[0]); j++)
			{
				if(output[i+j] == direc_str[j])
					direc_match[j] = output[i+j];	
			}
			printf("%s\n", direc_match);
		}
	}
	
	if(strcmp(direc_str, direc_match) == 0)
	{
		printf("%s\n", "Directives found.");
	} else {
		printf("%s\n", "No directives found.");
		return 1;
	}

	printf("Proceeding with program...\n");

	return 0;
}
