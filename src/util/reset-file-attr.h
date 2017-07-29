void reset_file_attr()
{
    //reset input file attributes 
    rewind(file.input);
    fclose(file.input);
    file.input_char = '\0';
	file.char_count = 0;
}
