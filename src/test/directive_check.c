#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "../file_attributes.h"
#include "../directive_check.h"

int main(int argc, char *argv[])
{
	char directive[] = {"##INCLUDE"};	

	if( direc_check(argv[1], directive ) )
		printf("Directive(s) found.\n");
	else
		printf("No directives found.\n");

	return 0;
}
