int get_longest_line_length(char *filename)
{
	int current_line = 0;
	int longest_line = 0;
	
    //open file for scanning
    file.input = fopen(filename, "r");

    //get char count of file
    while(file.input_char != EOF)
	{
		file.input_char = fgetc(file.input);
		current_line++;

		if(file.input_char == '\n')
		{
			if(current_line > longest_line)
				longest_line = current_line;
			
			current_line = 0;
		}
	};
	reset_file_attr();

    return longest_line;
}
