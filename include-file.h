// file containing inclusion directives 
FILE *infile;
char inchar;

// file to be included
FILE *newfile;
char newfilename[50];

char line[200]; // line in infile
char target[] = {"##INCLUDE"}; // inclusion directive
char targetmatch[sizeof(target)/sizeof(target[0])]; // where suspected directive match will be stored for comparison

void resetarrays()
{
	// Set each item in line and newfilename array to 0
    for(unsigned int k=0; k<sizeof(line)/sizeof(line[0]); k++)
    {
        line[k]=0;
    }
    for(unsigned int k=0; k<sizeof(newfilename)/sizeof(newfilename[0]); k++)
    {
        newfilename[k]=0;
    }
}
