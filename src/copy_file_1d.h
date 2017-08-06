//copy file to 1d array
void copy_file_1d( char *filename, int arr_size, char copy_str[arr_size])
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
