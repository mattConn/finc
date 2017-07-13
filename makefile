BINCHECK = if [ ! -d bin ]; then mkdir bin; fi; 

bin/include-file: src/main.c src/directive_detection.h src/scanner.h
	$(BINCHECK) gcc -Wall src/main.c -o bin/include-file;

check:
	bin/include-file test/poem.txt

all: bin/include-file check 

clean:
	rm -r bin 
