// Scan file specified in cli argument

#include "directive_matching.h"

char output_string[250000];

FILE *scanned_file;

char name_of_file_to_include[300];

char current_line_char[300];
int current_line_char_count = 0;
int char_count = 0;
int scanned_file_char_count = 0;

int times_scanner_ran = 0;

void reset_current_line_char()
{
	for(int i=0; i<sizeof(current_line_char)/sizeof(current_line_char[0]); i++)
		current_line_char[i] = 0;
}

//char scan_file(char *source_filename, char output_string)
const char *scan_file(char *source_filename)
{
	reset_current_line_char();
	char scanned_file_char;
	
	scanned_file = fopen(source_filename, "r");
	
	while(scanned_file_char != EOF)
	{
		scanned_file_char = fgetc(scanned_file);
		current_line_char[current_line_char_count] = scanned_file_char;
		current_line_char_count++;	

		char_count++;
		scanned_file_char_count++;

		if(scanned_file_char == '\n')
		{
			if(current_line_char[0] == directive[0] && current_line_char[1] == directive[1]) //check for first 2 chars. of directive
			{
				for(int i=0; i<sizeof(directive)/sizeof(directive[0]); i++)
				{
					if(directive_detection(current_line_char[i]))
					{
						current_pass_directive_count++;

						// copy source_filename from current line to name_of_file_to_include
						int source_filename_length = sizeof(current_line_char)/sizeof(current_line_char[0]) - sizeof(directive)/sizeof(directive[0]);
						//strncpy(name_of_file_to_include, &current_line_char[sizeof(directive)/sizeof(directive[0])-1],source_filename_length);
						strncpy(name_of_file_to_include, &current_line_char[sizeof(directive)/sizeof(directive[0])-1],source_filename_length);
						name_of_file_to_include[strlen(name_of_file_to_include)-1] = 0;
					}	


					// file to include is named and known here;
					// scanning of current doc should stop,
					// open specified file and scan. 
				
					//printf("%s",output_string);
					//exit(0);
					//break;
				}
				
				//rewind(scanned_file);
				return name_of_file_to_include;
				break;
				//printf("File to include: %s\n", name_of_file_to_include);
			} else {
				strcat(output_string, current_line_char);
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
			printf("Output:\n%s\n", output_string);
		} else {
			printf("No directives for inclusion (%s<filename>) found.\n", directive);
			exit(0);
		}
	} else { 
		total_directive_count = total_directive_count+current_pass_directive_count;
		current_pass_directive_count = 0;
		//rewind(scanned_file);
		//goto scanner_routine;	
	}
}
