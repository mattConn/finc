// argument validation for use in main function
void arg_validation(int arg_count, char *arg_vector){
    // check for file argument
    if(arg_count < 2)
    {
        printf("Missing file argument.\n");
		exit(1);
    }

    // check for valid file argument
    if( fopen(arg_vector, "r") == NULL  )
    {
        printf("Invalid file argument.\n");
		exit(1);
    }
}
