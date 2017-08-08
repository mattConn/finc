#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "file_attributes.h"
#include "argument_validation.h"
#include "util/directive_trim.h"
#include "directive_check.h"
#include "directive_locate.h"
#include "util/directive_arr_size.h"
#include "util/get_line_count.h"
#include "util/get_longest_line_length.h"
#include "copy_file.h"
#include "copy_file_1d.h"

int main(int argc, char *argv[])
{
	// check for valid argument
	arg_validation(argc, argv[1]);

	// define directive string
	char directive[] = {"##include"};
	
	// copy arg to string
	char *arg = argv[1];
	char arg_str[strlen(arg)];	
	strcpy(arg_str, arg);	

	// check if any directives present in file, end program if none
	if( !direc_check(argv[1], directive) )
	{
		printf("No directives present in \"%s\".\n", arg_str);
		return 1;
	}

	// trim filename from arg path for later chdir
	int arg_len = strlen(arg_str);
	while(arg_str[arg_len] != '/')
	{
		arg_str[arg_len] = '\0';	
		arg_len--;
	}

	//
	// Arguments are valid and directives are present,
	// program proceeds.
	//	

	//copy file to file string
    char file_str[ get_line_count(argv[1]) ][ get_longest_line_length(argv[1]) ];
    copy_file(argv[1], get_longest_line_length(argv[1]), file_str);

    // get amount of directives in file string
    int locations_len = direc_arr_size( get_longest_line_length(argv[1]), file_str, directive );

    // declare array of directive indices for locating directives in file string
    int location_arr[locations_len];

    // assign directive indices to respective array
    direc_locate( get_longest_line_length(argv[1]), file_str, directive, location_arr );
	
	// array for trimmed found directives
	char trimmed_direc[ get_longest_line_length(argv[1]) ];

	// change directory to directory of main file (via trimmed argv)
	chdir(arg_str);

	// get largest file (via greatest char count)
    int longest_char_count = 0;
    for(int i = 0; i < sizeof(location_arr)/sizeof(location_arr[0]); i++)
    {
    	int char_count = 0;

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
    }

	// send original file and included file contents to stdout
	int location_index = 0;
    for(int i = 0; i < sizeof(file_str)/sizeof(file_str[0]); i++)
	{
		if(i == location_arr[location_index]) //if index is listed in location arr as directive
		{
			// name of file to open, trimmed for directive
        	direc_trim(file_str[ location_arr[location_index] ], directive, strlen(file_str[ location_arr[location_index] ]) - strlen(directive), trimmed_direc);

			// copy listed file to string
   			char included_str[ get_line_count(trimmed_direc) ][ get_longest_line_length(trimmed_direc) ];
   			copy_file(trimmed_direc, get_longest_line_length(trimmed_direc), included_str);

			// send string to stdout
    		for(int k = 0; k < sizeof(included_str)/sizeof(included_str[0]); k++)
				printf("%s\n", included_str[k]);
			
			// move to next location
			location_index++;
		} else {
			// print main file's string
			printf("%s\n", file_str[i]);
		}
	}
	

	return 0;
}
