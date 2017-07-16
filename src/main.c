#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

FILE *file_to_include;
char file_to_include_char;
char next_file[2000];


#include "scanner.h"

int main(int argc, char *argv[])
{
	strcpy( next_file, scan_file(argv[1]) );
	//printf("%s", next_file);
	//scan_file(next_file);
	printf("%s\n",output_string);
}

/*
int main(int argc, char *argv[])
{

	printf("Output (via return):\n%s",scan_file(argv[1]));
	printf("%s\n",output_string);
}
*/
