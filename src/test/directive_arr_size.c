#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "../file_attributes.h"
#include "../util/get_line_count.h"
#include "../util/directive_arr_size.h"
#include "../util/get_longest_line_length.h"
#include "../get_char_count.h"
#include "../copy_file.h"
#include "../directive_locate.h"

int main(int argc, char *argv[])
{

	char directive[] = {"##INCLUDE"};

	char test_str[ get_line_count(argv[1]) ][ get_longest_line_length(argv[1]) ];
	
	copy_file(argv[1], get_longest_line_length(argv[1]), test_str);
	
//	for(int i = 0; i < sizeof(test_str)/sizeof(test_str[0]); i++)
//		printf("%s", test_str[i]);

	printf( "%d\n", direc_arr_size( get_longest_line_length(argv[1]),test_str, directive) );

	//direc_locate(get_longest_line_length(argv[1]),test_str, directive);

	

	return 0;
}
