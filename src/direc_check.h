bool direc_check(char *filename, char *direc_str)
{
	int matched = 0;

    //open file for scanning
    file.input = fopen(filename, "r");

    //get char count of file
    while(matched != sizeof(direc_str)/sizeof(direc_str[0]) || file.input_char != EOF)
    {
        file.input_char = fgetc(file.input);
		if(file.input == direc_string[matched])
			matched++;
		else
			matched = 0;
    };

    reset_file_attr();
	
	if( matched == sizeof(direc_str)/sizeof(direc_str[0]) )
		return true;
	else
		return false;
}
