#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "../file_attributes.h"
#include "../util/get_line_count.h"

int main(int argc, char *argv[])
{
	printf("%s: %d\n", "Line count", get_line_count(argv[1]) );
	
	return 0;
}
