int get_char_count(char *filename)
{
	int char_count = 0;
	file.char_count = 0;
	
    //open file for scanning
    file.input = fopen(filename, "r");

    //get char count of file.ment
    while(file.input_char != EOF)
	{
		file.input_char = fgetc(file.input);
        file.char_count++;
	};

	char_count = file.char_count;

    //reset: back to top of input, reset file.ment char count 
    rewind(file.input);
    file.char_count = 0;

    return char_count;
}

