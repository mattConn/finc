# finc (File INClude)
File-including utility.

## Building
Run `make` to compile with g++. Binary will be `bin/finc`.  
Run `make check` to see how finc handles the files in `test/several_directives` as an example of functionality.  
To use a different compiler and set flags, edit the appropriate lines in makefile.

## Usage
Usage: `finc [FILE]`  
Include files in  [FILE] listed by inclusion directives.  
The final result will be sent to stdout. Redirect this output to another file to save your results.

Example usage:  
`finc src/index.html > dist/index.html`

Example directive:  
`##include includes/head.html`

Note that quotation marks aren't needed around the name of the file to be included.  

finc is licensed under GPL-3.0.
<https://www.gnu.org/licenses/gpl-3.0.en.html>  
finc homepage: <http://git.mattconn.io/finc.git/>

## Limitations
finc currently can only process one file (containing any number of directives) at a time, and can only send output to stdout.  

A loop is one way to process several files.  
Below is an example of such a loop:

    #!/bin/bash
    cd html;
    for f in *
        do
            finc $f > ../../dist/$f
        done

finc can also only process directives nested one level deep; includes within included files will not be processed on only a single run of finc.

## Wanted Features
-   Processing of multiple files at a time
-   Processing of directives nested deeper than one level on a single
    run
-   Writing to file without stdout redirect
-   Verbose mode (possible without reliance on stdout)
