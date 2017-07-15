#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "scanner.h"

char test[250000];

int main(int argc, char *argv[])
{
	scan_file(argv[1]);
	printf("Number of directives found: %d\n",total_directive_count);
	printf("Output:\n%s", output_text);
}
