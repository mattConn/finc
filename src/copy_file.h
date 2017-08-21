//copy file to 1d array
std::string copy_file( char *filename )
{
    //open file for scanning
	FILE *input;
    input = fopen(filename, "r");
	std::string file_str;

	char input_char;

    //get char count of file
    while(input_char != EOF)
	{
		input_char = fgetc(input);

		file_str.push_back(input_char);
	};

	file_str[ file_str.size()-2 ] = '\0';
	return file_str;
}
