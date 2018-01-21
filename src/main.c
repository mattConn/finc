#include <stdio.h>
#include <iostream>
#include <fstream>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>
#include <string>
#include <string.h>
#include <vector>

#include "copy_file.h"
#include "user_help_strings.h"
#include "argument_validation.h"

int main(int argc, char *argv[])
{

	std::string directive = argc > 2 ? argv[2] : "#include"; // if no directive is specified by user, default to C directive
	std::string file_str, file_dir, target_file, include_file_contents;

	if( !arg_validation(argc, argv[1]) )
		return 1;

	// copy file to string
	file_str = copy_file(argv[1]);

	// trim filename from arg path for chdir
	file_dir = argv[1];
	int i = file_dir.size()-1;
	while(file_dir[i] != '/' && i >= 0)
	{
		file_dir[i] = '\0';	
		i--;
	}
	
	// cd to directory of file if needed
	if(file_dir.size() > 0)
		chdir( file_dir.c_str() );

	// find directives, then open and print listed files
	std::string matched;
	for(int i = 0; i < file_str.size()-1; i++)
	{
		// if possible directive
		if(file_str[i] == '#' && file_str[i+1] == 'i' && file_str[i+2] == 'n')
		{
			// confirm directive
			int j = i;
			while(file_str[j] != '\n' && file_str[j] != ' ')
			{
				matched.push_back(file_str[j]);
				j++;
			}

			// if actual directive
			if(matched == directive)
			{
				matched.clear();
				i += directive.size() + 1;
	
				// get file name listed by directive
				while(file_str[i] != '\n')
				{
					target_file.push_back(file_str[i]);	
					i++;
				}

				// open listed file
				std::ifstream include_file;
				include_file.open(target_file.c_str());

				// if unable to open, throw error
				if(include_file.fail())
					std::cout << "**ERROR** Failed to open " << file_dir << target_file << std::endl;

				// print included file
				std::cout << include_file.rdbuf();

				// close file, clear target file
				include_file.close();
				target_file.clear();
			} else {
				// false positive, proceed with scanning file_str
				matched.clear();
			}
		} else {
			// print main file
			std::cout << file_str[i];
		}
	}

	return 0;
}
