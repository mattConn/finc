#include "util/reset-file-attr.h"

int get_char_count(char *filename)
{
	int char_count = 0;
	
    //open file for scanning
    file.input = fopen(filename, "r");

    //get char count of file
    while(file.input_char != EOF)
	{
		file.input_char = fgetc(file.input);
        file.char_count++;
	};

	char_count = file.char_count;

	reset_file_attr();

    return char_count;
}
