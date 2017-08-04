#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "file_attributes.h"
#include "util/get_line_count.h"
#include "util/get_longest_line_length.h"
#include "get_char_count.h"

int main(int argc, char *argv[])
{
	//Copy file to string 
    char file_str[ get_line_count(argv[1]) ][ get_longest_line_length(argv[1]) ];
    
    int char_count = 0;
    int line_count = 0;

    //open file for scanning
    file.input = fopen(argv[1], "r");
    
    //get char count of file
    while(file.input_char != EOF)
    {
        file.input_char = fgetc(file.input);
        
        file_str[line_count][char_count] = file.input_char;
        char_count++;

        if(file.input_char == '\n')
        {
            file_str[line_count][char_count] = '\0';
            line_count++;
            char_count = 0;
        }
    };
    reset_file_attr();



	for(unsigned int i = 0; i<sizeof(file_str)/sizeof(file_str[0]);i++)
		printf("%s", file_str[i]);

	return 0;
}
