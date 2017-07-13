#include <stdio.h>
#include <stdbool.h>

FILE *scanned_file;
char directive[] = {"##INCLUDE"};
int directive_count = 0;	

#include "directive_detection.h"
#include "scanner.h"

int main(int argc, char *argv[])
{
	scan_file(argv[1]);
	printf("directives found: %d\n",directive_count);
}
