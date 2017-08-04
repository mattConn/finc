#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "../file_attributes.h"
#include "../util/get_line_count.h"
#include "../util/get_longest_line_length.h"
#include "../get_char_count.h"
#include "../copy_file.h"

int main(int argc, char *argv[])
{

	char test_str[ get_line_count(argv[1]) ][ get_longest_line_length(argv[1]) ];
	
	copy_file(argv[1], test_str);

	return 0;
}
