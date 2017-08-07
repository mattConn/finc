#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "../file_attributes.h"
#include "../util/get_line_count.h"
#include "../util/directive_arr_size.h"
#include "../util/get_longest_line_length.h"
#include "../get_char_count.h"
#include "../copy_file.h"
#include "../directive_locate.h"

int main(int argc, char *argv[])
{
//int direc_arr_size(int file_arr_size, char file_str[][file_arr_size], char *direc_str)

	char directive[] = {"##include"};

	char test_str[ get_line_count(argv[1]) ][ get_longest_line_length(argv[1]) ];
	
	copy_file(argv[1], get_longest_line_length(argv[1]), test_str);
	
	int locations_size = direc_arr_size( get_longest_line_length(argv[1]), test_str, directive );

	int locations[ locations_size ];

	direc_locate(get_longest_line_length(argv[1]),test_str, directive, locations);

	for(int i = 0; i < locations_size; i++)
		printf("%d\n", locations[i]);

	return 0;
}
