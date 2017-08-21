#include <stdio.h>
#include <iostream>
#include <fstream>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>
#include <string>
#include <vector>

#include "copy_file.h"

int main(int argc, char *argv[])
{

	// define directive string
	std::string directive = "##include", file_str, target_file, include_file_contents;
	
	file_str = copy_file(argv[1]);
	
	chdir("test/several_directives");
	std::string matched;
	for(int i = 0; i < file_str.size(); i++)
	{
		if(file_str[i] == '#' && file_str[i+1] == '#' && file_str[i+2] == 'i')
		{
			int j = i;
			while(file_str[j] != '\n' && file_str[j] != ' ')
			{
				matched.push_back(file_str[j]);
				j++;
			}
			if(matched == directive)
			{
				matched.clear();
				i += directive.size() + 1;
				while(file_str[i] != '\n')
				{
					target_file.push_back(file_str[i]);	
					i++;
				}

				std::ifstream include_file;
				include_file.open(target_file.c_str());

				if(include_file.fail())
					std::cout << "FILE FAILURE\n";

				while(include_file.good())
				{
					//std::cout << (char)include_file.get();
					include_file_contents.push_back( (char)include_file.get() );
				}
				include_file_contents.back() = '\0';
				std::cout << include_file_contents;

				include_file_contents.clear();

				target_file.clear();
			}
		} else {
			printf("%c", file_str[i]);
		}
	}

	return 0;
}
