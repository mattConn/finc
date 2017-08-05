// find num of directives
int direc_arr_size(int file_arr_size, char file_str[][file_arr_size], char *direc_str)
{

	int matched = 0;

	int locations_length = 0;

	//check for consecutive matching characters in file against directive
	for(int i = 0; i < strlen(file_str); i++)
    {
		for(int j = 0; j < sizeof(direc_str)/sizeof(direc_str[0]); j++)
		{
			if(file_str[i][j] == direc_str[j])
				matched++;
			else
				matched = 0;

			if( matched == sizeof(direc_str)/sizeof(direc_str[0]) )
			{
				locations_length++;
				matched = 0;
			}
		}
	
    };

	return locations_length;
}
