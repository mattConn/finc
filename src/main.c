#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

char output_text[250000];

#include "scanner.h"

int main(int argc, char *argv[])
{
	scan_file(argv[1]);
	//printf("Number of directives found: %d\n",total_directive_count);
}
