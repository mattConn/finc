#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "file_attributes.h"
#include "util/directive_trim.h"
#include "directive_locate.h"
#include "util/directive_arr_size.h"
#include "util/get_line_count.h"
#include "util/get_longest_line_length.h"
#include "copy_file.h"
#include "copy_file_1d.h"

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
	
	// array for trimmed found directives
	char trimmed_direc[ get_longest_line_length(argv[1]) ];

	// find longest file for sizing 2d included file array
	chdir("test/several_directives");

    int longest_char_count = 0;
    for(int i = 0; i < sizeof(location_arr)/sizeof(location_arr[0]); i++)
    {
    	int char_count = 0;

		// TODO: arr of file names
		// name of file to open, trimmed for directive
        direc_trim(file_str[ location_arr[i] ], directive, strlen(file_str[ location_arr[i] ]) - strlen(directive), trimmed_direc);

        //open file for scanning
        file.input = fopen(trimmed_direc, "r");

        //get char count of file
        while(file.input_char != EOF)
        {
            file.input_char = fgetc(file.input);
            char_count++;
        };

        reset_file_attr();

        if(char_count > longest_char_count)
            longest_char_count = char_count;

		/*
        printf("%d\n", longest_char_count);
		*/
    }

	// content of files to be included
	char included_files[locations_len][longest_char_count];

	char foo[longest_char_count];
	// copy included files to relevant array
    for(int i = 0; i < locations_len; i++)
    {
		// name of file to open, trimmed for directive
        direc_trim(file_str[ location_arr[i] ], directive, strlen(file_str[ location_arr[i] ]) - strlen(directive), trimmed_direc);

    	//copy_file_1d(trimmed_direc, longest_char_count, &included_files[i]);
    	copy_file_1d(trimmed_direc, longest_char_count, &included_files[i]);
    }
		
    for(int i = 0; i < locations_len; i++)
		printf("%s", included_files[i]);

	return 0;
}
