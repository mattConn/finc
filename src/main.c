#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#include "scanner.h"

int main(int argc, char *argv[])
{
	scan_file(argv[1]);
	printf("directives found: %d\n",directive_count);
}