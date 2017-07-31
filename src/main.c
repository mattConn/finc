#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "file-attributes.h"
#include "get-char-count.h"
#include "copy-file.h"

int main(int argc, char *argv[])
{
	char output[ get_char_count(argv[1]) ];
	copy_file(argv[1], output);

	printf("Proceeding with program...\n");

	return 0;
}
