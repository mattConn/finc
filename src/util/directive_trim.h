void direc_trim(char *str, char *directive, int size, char trimmed_dir_str[size] )
{
	strncpy( trimmed_dir_str, &str[ ( sizeof(directive)/sizeof(directive[0])+2 ) ], strlen(str) - strlen(&directive) );
}
