// argument validation for use in main function
void arg_validation(int arg_count, char *arg_vector){
	char help_message[] = {"Try \"finc -h\" for usage/information."};

    // check for file argument
    if(arg_count < 2)
    {
        printf("Missing file argument.\n%s\n", help_message);
		exit(1);
    }

    // check for valid file argument
    if( fopen(arg_vector, "r") == NULL  )
    {
        printf("Invalid file argument.\n%s\n", help_message);
		exit(1);
    }
}
