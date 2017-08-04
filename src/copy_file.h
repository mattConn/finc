void copy_file( char *filename, char copy_str)
{
	int line_count = 0;
	int char_count = 0;
	
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
			copy_str[line_count][char_count] = '\0';
			//printf("%s", copy_str[line_count]);
			line_count++;
			char_count = 0;
		}
	};
	
	reset_file_attr();

}
