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

    //reset input file attributes 
    rewind(file.input);
	fclose(file.input);
    file.input_char = '\0';
    file.char_count = 0;

    return char_count;
}
