char help_notice[] = {"Try \"finc -h\" for usage/information."};

char help_message[] = "Usage: finc [FILE]\n\\
Include files in [FILE] through inclusion directives written in [FILE].\n\\
The final result will be sent to stdout. Redirect this output to another file to save your results.\n\
\n\
Example usage:\n\
finc src/index.html > dist/index.html\n\
\n\
Example directive:\n\
##include head.html\n\
\n\
Note that the inclusion directive should be written at the start of a new line.\n\
Also note that quotation marks aren't needed around the name of the file to be included.\n\
\n\
finc is licensed under GPL-3.0. <https://www.gnu.org/licenses/gpl-3.0.en.html>\n\
finc homepage: <http://git.mattconn.io/finc.git/>";
