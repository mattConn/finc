std::string help_notice = "Try \"finc -h\" for usage/information.";

std::string help_message = "Usage: finc [FILE]\n\
Include files in [FILE] listed by inclusion directives.\n\
The final result will be sent to stdout. Redirect this output to another file to save your results.\n\
\n\
Example usage:\n\
finc src/index.html > dist/index.html\n\
\n\
Example directive:\n\
##include includes/head.html\n\
\n\
Note that quotation marks aren't needed around the name of the file to be included.\n\
\n\
finc was written by Matthew Connelly, 2017.\n\
finc is licensed under GPL-3.0. <https://www.gnu.org/licenses/gpl-3.0.en.html>\n\
finc homepage: <http://git.mattconn.io/finc.git/>";
