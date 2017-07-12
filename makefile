include-file: include-file.c include-file.h
	gcc -Wall include-file.c -o include-file;

check:
	./include-file test/test.txt

all: include-file check 

clean:
	rm include-file
