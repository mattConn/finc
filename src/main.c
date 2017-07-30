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
	char direc[] = {"##INCLUDE"};

	bool has_direc = false;

	for(int i = 0; i < sizeof(output)/sizeof(output[0]); i++)
	{
		if(output[i] == direc[0] && output[i+1] == direc[1])
			has_direc = true;	
	}

	if(!has_direc)
	{
		printf("%s\n", "No directives found.");
		return 1;
	} else {
		printf("%s\n", "Directives found.");
	}

	return 0;
}
