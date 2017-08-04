char copy_file( char *filename, int input_line_count, int input_line_length )
{
	char copy_str[input_line_count][input_line_length];

	int char_count = 0;
	int line_count = 0;
	
    //open file for scanning
    file.input = fopen(filename, "r");

    //get char count of file
    while(file.input_char != EOF)
	{
		file.input_char = fgetc(file.input);

		copy_str[line_count][char_count] = file.input_char;
        char_count++;
		
		if(file.input_char == '\n')
		{
			line_count++;
			char_count = 0;
		}
	};
	
	reset_file_attr();

	return copy_str;

}
