#include <stdio.h>
#include "include-file.h"

int main(int argc, char *argv[])
{

	resetarrays();	

    infile = fopen(argv[1], "r");
    if (infile == NULL)
    {
        printf("Invalid file argument.\n");
		return 1;
    }

	unsigned int i = 0;
    while (inchar != EOF)
    {
        inchar = fgetc(infile);
		// check our string upon reaching end of current line
		if(inchar == '\n')
		{
			// if beginning of line is preceeded by target delimiter
			if(line[0]==target[0] && line[1]==target[1])
			{
				for(unsigned int j=0; j<sizeof(target)/sizeof(target[0]);j++)
				{
					if(line[j] == target[j])
						targetmatch[j] = line[j];	
				}

				if(strcmp(target, targetmatch) == 0)
				{
					unsigned int b = 0;
					for(unsigned int a = sizeof(target)/sizeof(target[0]); a < sizeof(line)/sizeof(line[0]); a++)
					{
						newfilename[b] = line[a];
						b++;
						// TODO: segmentation fault
					}
					newfile = fopen(newfilename, "r");
					printf("%d\n", newfile);
				}
			}

			// then reset line and iterator
			for(unsigned int j=0; j<sizeof(line)/sizeof(line[0]);j++)
			{
				line[j] = 0;
			}
			i = 0;
		} else {
			// add characters to line array
			line[i] = inchar;
			i++;
		}
    }
	
 
    fclose(infile);
    return 0;
}
