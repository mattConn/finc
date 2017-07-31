void copy_file(char *filename, char *copy_str)
{
	int char_count = 0;
	
    //open file for scanning
    file.input = fopen(filename, "r");

    //get char count of file
    while(file.input_char != EOF)
	{
		file.input_char = fgetc(file.input);
		copy_str[char_count] = file.input_char;
        char_count++;
	};
	
	reset_file_attr();
}
