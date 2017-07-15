// Scan file specified in cli argument

#include "directive_matching.h"

FILE *scanned_file;

char output_text[250000];
char name_of_file_to_include[300];

char current_line_char[300];
int current_line_char_count = 0;
int char_count = 0;

int times_scanner_ran = 0;

void reset_current_line_char()
{
	for(int i=0; i<sizeof(current_line_char)/sizeof(current_line_char[0]); i++)
	{
		current_line_char[i] = 0;
	}
}

void scan_file(char *filename)
{

	reset_current_line_char();
	char scanned_file_char;
	
	scanned_file = fopen(filename, "r");

	scanner_routine:
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
						//printf("%s\n", current_line_char);
						current_pass_directive_count++;
						
					}	
				}
			} else {
				strcat(output_text, current_line_char);
			}
			
			current_line_char_count = 0;
			reset_current_line_char();
		}
	}
	times_scanner_ran++;

	
	// if no direcitves, terminate program
	if(current_pass_directive_count == 0)
	{
		if(times_scanner_ran > 1)
		{
			printf("Number of files included: %d\nNumber of passes: %d\n",current_pass_directive_count,times_scanner_ran);
			printf("Output:\n%s\n", output_text);
		} else {
			printf("No directives for inclusion (%s<filename>) found.\n", directive);
			exit(0);
		}
	} else { 
		total_directive_count = total_directive_count+current_pass_directive_count;
		current_pass_directive_count = 0;
		rewind(scanned_file);
		//goto scanner_routine;	
	}

}
