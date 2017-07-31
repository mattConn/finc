#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "../file_attributes.h"
#include "../get_char_count.h"

int main(int argc, char *argv[])
{
	printf("%s: %d\n", "infile character count", get_char_count(argv[1]) );
	printf("%s: %d\n", "\'file.char_count\'", file.char_count );
	
	return 0;
}
