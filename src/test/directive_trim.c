#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "../file_attributes.h"
#include "../util/directive_trim.h"
#include "../directive_locate.h"
#include "../util/directive_arr_size.h"
#include "../util/get_line_count.h"
#include "../util/get_longest_line_length.h"
#include "../copy_file.h"

int main(int argc, char *argv[])
{
	char directive[] = {"##INCLUDE"};

	//copy file to string
    char file_str[ get_line_count(argv[1]) ][ get_longest_line_length(argv[1]) ];
    copy_file(argv[1], get_longest_line_length(argv[1]), file_str);

    // get amount of directives in file string
    int locations_len = direc_arr_size( get_longest_line_length(argv[1]), file_str, directive );

    // declare array of directive indices
    int location_arr[locations_len];

    // assign directive indices to respective array
    direc_locate( get_longest_line_length(argv[1]), file_str, directive, location_arr );
	
	// trim found directives
	char trimmed_direc[ get_longest_line_length(argv[1]) ];
	for(int i = 0; i < sizeof(location_arr)/sizeof(location_arr[0]); i++)
	{
		direc_trim(file_str[ location_arr[i] ], directive, strlen(file_str[ location_arr[i] ]) - strlen(directive), trimmed_direc);
		printf("%s", trimmed_direc);
	}

	return 0;
}
