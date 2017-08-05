#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "file_attributes.h"
#include "util/get_line_count.h"
#include "util/get_longest_line_length.h"
#include "util/directive_arr_size.h"
#include "directive_check.h"
#include "directive_locate.h"
#include "get_char_count.h"
#include "copy_file.h"

int main(int argc, char *argv[])
{
	char directive[] = {"##INCLUDE"};
	char file_copy[ get_line_count(argv[1]) ][ get_longest_line_length(argv[1]) ];

	// check if directives present in file
	if( !direc_check(argv[1], directive) )
	{
		printf("No directives found.\n");
		return 1;
	}

	// copy file to string
	copy_file(argv[1], get_longest_line_length(argv[1]), file_copy);
	
	// get amount of directives in file string
	int locations_len = direc_arr_size( get_longest_line_length(argv[1]), file_copy, directive );

	// declare array of directive indices
	int location_arr[locations_len];
	
	// assign directive indices to respective array
	direc_locate( get_longest_line_length(argv[1]), file_copy, directive, location_arr );

	printf("Number of dir. locations: %d\n", locations_len);

	for(int i = 0; i < locations_len; i++)
		printf("%d\n", location_arr[i]);

	
	return 0;
}
