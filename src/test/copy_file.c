#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "../file_attributes.h"
#include "../get_char_count.h"
#include "../copy_file.h"

int main(int argc, char *argv[])
{
	char test_str1[ get_char_count(argv[1]) ];
	char test_str2[ get_char_count(argv[1]) ];

	copy_file(argv[1], test_str1);
	copy_file(argv[1], test_str2);

	printf("Test string 1:\n%s\nTest string 2:\n%s\n",test_str1, test_str2);
	
	return 0;
}
