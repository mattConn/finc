void copy_file( char *filename, int arr_size, char copy_str[][arr_size])
{
	int line_count = 0;
	int char_count = 0;
	
    //open file for scanning
    file.input = fopen(filename, "r");

    //get char count of file
    while(file.input_char != EOF)
	{
		file.input_char = fgetc(file.input);
		
		if(file.input_char == '\n')
		{
			copy_str[line_count][char_count] = '\0';
			char_count = 0;

			line_count++;

		} else {
			copy_str[line_count][char_count] = file.input_char;
        	char_count++;
		}
	};
	
	reset_file_attr();

}
