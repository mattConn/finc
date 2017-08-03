int get_line_count(char *filename)
{
	int line_count = 0;
	
    //open file for scanning
    file.input = fopen(filename, "r");

    //get char count of file
    while(file.input_char != EOF)
	{
		file.input_char = fgetc(file.input);

		if(file.input_char == '\n')
		{
			line_count++;
		}
	};
	reset_file_attr();

    return line_count;
}
