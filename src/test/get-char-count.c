#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "../file-attributes.h"
#include "../get-char-count.h"

int main(int argc, char *argv[])
{
	// call get-char-count setting file.char_count
	if( argc > 2 && strcmp(argv[2], "-s") == 0 )
	{
		printf("%s: %d\n", "infile character count", get_char_count(argv[1], 's') );
		printf("%s: %d\n", "\'file.char_count\'", file.char_count);
	} else {
		// call without setting
		printf("%s: %d\n", "infile character count", get_char_count(argv[1], ' ') );
		printf("%s: %d\n", "\'file.char_count\'", file.char_count);
	}
	
	return 0;
}
