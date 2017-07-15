// Scan file specified in cli argument

#include "directive_matching.h"

FILE *scanned_file;

char current_line_char[200];
int current_line_char_count = 0;

void reset_current_line_char()
{
	for(int i=0; i<sizeof(current_line_char)/sizeof(current_line_char[0]); i++)
	{
		current_line_char[i] = 0;
	}
}

void scan_file(char *filename)
{
	int char_count = 0;

	reset_current_line_char();
	char scanned_file_char;
	
	scanned_file = fopen(filename, "r");

	while(scanned_file_char != EOF)
	{
		scanned_file_char = fgetc(scanned_file);
		current_line_char[current_line_char_count] = scanned_file_char;
		current_line_char_count++;	

		char_count++;

		if(scanned_file_char == '\n')
		{
			if(current_line_char[0] == directive[0] && current_line_char[1] == directive[1]) //check for first 2 chars. of directive
			{
				for(int i=0; i<sizeof(directive)/sizeof(directive[0]); i++)
				{
					if(directive_detection(current_line_char[i]))
					{
						printf("%s\n", current_line_char);
						directive_count++;
					}	
				}
			}
			
			current_line_char_count = 0;
			reset_current_line_char();
		} 
	}
	
	// if no direcitves, terminate program
	if(directive_count == 0)
	{
		printf("No directives for inclusion (%s<filename>) found.\n", directive);
		exit(0);
	}
}
