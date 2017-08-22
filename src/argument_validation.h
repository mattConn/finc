// argument validation for use in main function
bool arg_validation(int arg_count, char *arg_vector){
	
	bool valid = true;

    // check for file argument
    if(arg_count < 2)
    {
        std::cout << "Missing file argument.\n" << help_notice << std::endl;
		valid = false;
		return valid;
    }

    if( strcmp(arg_vector, "-h") == 0 )
    {
        std::cout << help_message << std::endl;
		valid = false;
		return valid;
    }

    // check for valid file argument
    if( fopen(arg_vector, "r") == NULL  )
    {
        std::cout << "Invalid file argument.\n" <<  help_notice << std::endl;
		valid = false;
		return valid;
    }

	return valid;
}
