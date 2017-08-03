#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "../file_attributes.h"
#include "../util/get_longest_line_length.h"

int main(int argc, char *argv[])
{
	printf("%s: %d\n", "Longest line length", get_longest_line_length(argv[1]) );
	
	return 0;
}
