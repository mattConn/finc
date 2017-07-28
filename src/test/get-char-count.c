#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "../file-attributes.h"
#include "../get-char-count.h"

int main(int argc, char *argv[])
{
	printf("%d\n", get_char_count(argv[1]));
}
