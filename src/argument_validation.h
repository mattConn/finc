// argument validation for use in main function
bool arg_validation(int arg_count, char *arg_vector){
	
	bool valid = true;

	char help_notice[] = {"Try \"finc -h\" for usage/information."};

    // check for file argument
    if(arg_count < 2)
    {
        printf("Missing file argument.\n%s\n", help_notice);
		valid = false;
		return valid;
    }

    if( strncmp(arg_vector, "-h", 2) == 0 )
    {
        printf("<finc usage>\n");
		valid = false;
		return valid;
    }

    // check for valid file argument
    if( fopen(arg_vector, "r") == NULL  )
    {
        printf("Invalid file argument.\n%s\n", help_notice);
		valid = false;
		return valid;
    }

	return valid;
}
