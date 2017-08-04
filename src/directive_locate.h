// find num of directives (if any),
// then list their locations (indices)

int direc_locate(int arr_size, char file_str[][arr_size], char *direc_str)
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

	if( locations_length < 1)
	{
		printf("No directives present.\n");
		return 1;
	}

	//list directive locations
	int locations[locations_length];
	int locations_index = 0;

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
				locations[locations_index] = i;
				locations_index++;
				matched = 0;
			}
		}
	
    };
	
	for(int i = 0; i < sizeof(locations)/sizeof(locations[0]); i++)	
		printf("%d\n", locations[i]);	

	return locations;
}
