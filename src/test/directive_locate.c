#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "../file_attributes.h"
#include "../util/get_line_count.h"
#include "../util/get_longest_line_length.h"
#include "../copy_file.h"
#include "../directive_locate.h"

int main(int argc, char *argv[])
{
	char directive[] = {"##INCLUDE"};	

	char test_str[ get_line_count(argv[1]) ][ get_longest_line_length(argv[1]) ];

	//printf( "%d\n", direc_locate(get_longest_line_length(argv[1]), test_str, directive) );
	direc_locate(get_longest_line_length(argv[1]), test_str, directive);
	

}
