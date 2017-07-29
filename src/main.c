#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "file-attributes.h"
#include "get-char-count.h"

int main(int argc, char *argv[])
{
	char foo[get_char_count(argv[1])];
	
	

	return 0;
}
