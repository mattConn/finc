void scan_file(char *filename)
{
	int char_count = 0;

	char scanned_file_char;
	
	scanned_file = fopen(filename, "r");

	while(scanned_file_char != EOF)
	{
		scanned_file_char = fgetc(scanned_file);
		char_count++;

		if(directive_detection(scanned_file_char))
			directive_count++;	
		//printf("%d\n",directive_detection(scanned_file_char));
		//char_count++;
	}
}
