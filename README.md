# finc (File INClude)
Small program written in C to include files in development; alternative to SSI (server-side includes).

## Usage
Usage: `finc [FILE]`
Include files in `[FILE]` through inclusion directives written in `[FILE]`.
The final result will be sent to stdout. Redirect this output to another file to save your results.

Example usage:
`finc src/index.html > dist/index.html`

Example directive:
`##include head.html`

Note that the inclusion directive should be written at the start of a new line.
Also note that quotation marks aren't needed around the name of the file to be included.

finc is licensed under GPL-3.0. <https://www.gnu.org/licenses/gpl-3.0.en.html>
finc homepage: <http://git.mattconn.io/finc.git/>

## Limitations
finc currently can only process one file (containing any number of directives) at a time, and can only send output to stdout.  

A loop is one way to process several files.  
Below is an example of such a loop:  
```
#!/bin/bash
cd html;
for f in *
	do
		finc $f > ../../dist/$f
	done
```
finc can also only process directives nested one level deep; includes within included files will not be processed on only a single run of finc.

## Wanted Features
- Processing of multiple files at a time
- Processing of directives nested deeper than one level on a single run
- Writing to file without stdout redirect
- Verbose mode (possible without reliance on stdout)

## Development
See `DEVELOPMENT.md`.
