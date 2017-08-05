// find num of directives (if any),
// then list their locations (indices)

int direc_locate(int arr_size, char file_str[][arr_size], char *direc_str, int *locations)
{

	if( direc_arr_size(arr_size, file_str, direc_str) < 1)
	{
		printf("No directives present.\n");
		return 1;
	}
	
	int matched = 0;

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

}
