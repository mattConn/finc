void direc_trim(char *str, char *directive, int size, char trimmed_dir_str[size] )
{
	// copy directive from str to trimmed dir str, from index <sizeof directive + 2 (for whitespace, next character)>
	// to end of str (<len of str - len of directive>).
	//
	//str = ##INCLUDE foo.txt
	//		          ^     ^
	//				  |     :
	//                str[sizeof(directive)/sizeof(directive[0])+2]
	//					    :
	//			            strlen(str) - strlen(&directive) == length of filename
	strncpy( trimmed_dir_str, &str[ ( sizeof(directive)/sizeof(directive[0])+2 ) ], strlen(str) - strlen(&directive) );
}
